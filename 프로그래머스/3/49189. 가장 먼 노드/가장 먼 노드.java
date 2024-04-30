import java.util.*;

class Solution {
    /*
        bfs로 들어가서 깊이를 구하는게 좋을 듯 하다.
    */
    
    static class Node {
        int node;
        int depth;
        
        Node(int node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }
    
    static Map<Integer, Set<Integer>> graph;
    
    static int maxLen = 0;
    
    static int cnt = 0;
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        graph = new HashMap<>();
        
        for(int i = 0; i <= n; i++) {
            graph.put(i, new HashSet<>());
        }
        for(int i = 0; i < edge.length; i++) {
            graph.get(edge[i][0]).add(edge[i][1]);
            graph.get(edge[i][1]).add(edge[i][0]);
        }
        
        bfs();        
        
        answer = cnt;
        
        return answer;
    }
    
    public static void bfs() {
        int[] visited = new int[graph.size()];
        Queue<Node> q = new LinkedList<>();
        
        visited[1] = 1;
        q.add(new Node(1, 0));
        
        while(!q.isEmpty()) {
            Node nn = q.poll();
            
            if(maxLen < nn.depth) {
                maxLen = nn.depth;
                cnt = 1;
            } else if (maxLen == nn.depth) {
                cnt++;
            }
            
            for(Integer num: graph.get(nn.node)) {
                if(visited[num] == 1) continue;
                
                visited[num] = 1;
                q.add(new Node(num, nn.depth + 1));
            }
        }
    }
}