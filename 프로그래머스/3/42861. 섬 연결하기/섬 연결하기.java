import java.util.*;

/*
    다익스트라 쓰는건가?
    와샬 하면 그냥 풀릴거같기도 하고ㅋㅋ
    n^3 = 1000000
*/

class Solution {
    static boolean log = true;
    static int mode = 1; // 0: Kruskal, 1: Prim
    
    // Kruskal
    static int[] parent;
    static int cost;
    
    // Prim
    static int[] nearest;
    static int[] distance;
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        
        if(mode==0) {
            answer = kruskal(n, costs);
        } else if(mode==1) {
            answer = prim(n, costs);
        }
                        
        return answer;
    }
    
    /////////////////////////////////////////////////
    
    static int kruskal(int n, int[][] costs) {
        // 초기화
        parent = new int[n];
        for(int i = 0; i < n; i++) parent[i] = i;
        
        Set<int[]> F = new HashSet<>();
        
        // 정렬
        Arrays.sort(costs, (o1, o2) -> {
            return o1[2] - o2[2];
        });
        
        if(log) printArr(parent);
        
        // Kruskal
        for(int i = 0; i < costs.length; i++) {    
            int[] e = costs[i];
            
            int a = e[0];
            int b = e[1];
            
            int p = find(a);
            int q = find(b);

            if(p != q) {
                union(p, q);
                F.add(e);
                cost += e[2];
            }
            
            if(log) printArr(parent);
        }
        
        return cost;
    }
    
    static void union(int p, int q) {
        if(p > q) parent[p] = q;
        else parent[q] = p;
    }
    
    static int find(int a) {
        if(parent[a] == a) return a;
        else return find(parent[a]);
    }
    
    /////////////////////////////////////////////////////
    
    static int prim(int n, int[][] costs) {
        // Initialize
        int[][] W = new int[n][n];
        for(int[] w: W) Arrays.fill(w, Integer.MAX_VALUE);
        for(int i =  0; i < n; i++) W[i][i] = 0;
        for(int[] cost: costs) {
            W[cost[0]][cost[1]] = cost[2];
            W[cost[1]][cost[0]] = cost[2];
        }
        
        nearest = new int[n];
        distance = new int[n];
        for(int i = 1; i < n; i++) {
            nearest[i] = 0;
            distance[i] = W[0][i];
        }
        
        for(int i = 1; i < n; i++) {
            int min = Integer.MAX_VALUE;
            int node = 0;
            
            for(int j = 1; j < n; j++) {
                if(distance[j] == -1) continue;
                
                if(min > distance[j]) {
                    min = distance[j];
                    node = j;
                }
            }
            
            cost += min;
            distance[node] = -1;
            
            for(int j = 1; j < n; j++) {
                if(W[node][j] < distance[j]) {
                    distance[j] = W[node][j];
                    nearest[j] = node;
                }
            }
        }
        
        return cost;
    }
    
    /////////////////////////////////////////////////////
    
    static void printArr(int[] arr) {
        for(int a: arr) {
            System.out.print(a+"\t");
        }
        System.out.println();
    }
}