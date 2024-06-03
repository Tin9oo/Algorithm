import java.util.*;

/*
    다익스트라 쓰는건가?
    와샬 하면 그냥 풀릴거같기도 하고ㅋㅋ
    n^3 = 1000000
*/

class Solution {
    static boolean log = false;
    static int mode = 0; // 0: Kruskal, 1: Prim
    
    //kruskal
    static int[] parent;
    static int cost;
        
    public int solution(int n, int[][] costs) {
        int answer = 0;
        
        if(mode==0) {
            answer = kruskal(n, costs);
        }
        
        if(log) printArr(parent);
                
        return answer;
    }
    
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
        parent[p] = q;
    }
    
    static int find(int a) {
        if(parent[a] == a) return a;
        else return find(parent[a]);
    }
    
    static void printArr(int[] arr) {
        for(int a: arr) {
            System.out.print(a+"\t");
        }
        System.out.println();
    }
}