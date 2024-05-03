import java.util.*;

class Solution {
    static final boolean LOG = false;
    
    static int INF;
    
    static ArrayList<ArrayList<Node>> graph;
    
    static int[] startA;
    static int[] startB;
    static int[] startS;
    
    static class Node implements Comparable<Node> {
        int idx;
        int cost;
        
        Node(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
        
        @Override
        public int compareTo(Node o) {
            return Integer.compare(this.cost, o.cost);
        }
    }
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        INF = 100001 * n;
        int answer = 100001 * n; // 연산할 때 INT_MAX를 더하면 오버플로우 난다. 주의
        
        graph = new ArrayList<>();
        for(int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for(int i = 0; i < fares.length; i++) {
            graph.get(fares[i][0]).add(new Node(fares[i][1], fares[i][2]));
            graph.get(fares[i][1]).add(new Node(fares[i][0], fares[i][2]));
        }
        
        // if(LOG) printGraph();
        
        /*floyd(graph, n);
        
        if(LOG) printGraph();
        
        for(int i = 1; i <= n; i++) {
            answer = Math.min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
        }*/
        
        startA = new int[n+1];
        startB = new int[n+1];
        startS = new int[n+1];
        
        Arrays.fill(startA, INF);
        Arrays.fill(startB, INF);
        Arrays.fill(startS, INF);
        
        dijkstra(startA, a);
        dijkstra(startB, b);
        dijkstra(startS, s);
        
        for(int i = 1; i <= n; i++) {
            answer = Math.min(answer, startA[i] + startB[i] + startS[i]);
        }
        
        return answer;
    }
    
    public static void dijkstra(int[] costs, int start) {
        int[] check = new int[costs.length - 1];
        
        PriorityQueue<Node> pq = new PriorityQueue<>(graph.get(start));
        
        for(Node node: graph.get(start)) {
            costs[node.idx] = node.cost;
        }
        costs[start] = 0;
        
        while(!pq.isEmpty()) {
            Node nowNode = pq.poll();
            
            for(Node node: graph.get(nowNode.idx)) {                
                if(costs[node.idx] > costs[nowNode.idx] + node.cost) {
                    costs[node.idx] = costs[nowNode.idx] + node.cost;
                    pq.offer(new Node(node.idx, costs[nowNode.idx] + node.cost));
                }
            }
        }
    }
    
    // public static void floyd(int[][] graph, int n) {
    //     for(int k = 1; k <= n; k++) {
    //         for(int i = 1; i <= n; i++) {
    //             for(int j = 1; j <= n; j++) {
    //                 graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
    //             }
    //         }
    //     }
    // }
    
    // public static void printGraph() {
    //     for(int[] gra: graph) {
    //         for(int g: gra) {
    //             System.out.print(g+"\t");
    //         }
    //         System.out.println();
    //     }
    //     System.out.println();
    // }
}