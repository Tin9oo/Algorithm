import java.util.*;

class Solution {
    static final boolean LOG = false;
    static int[][] graph;
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = 100001 * n; // 연산할 때 INT_MAX를 더하면 오버플로우 난다. 주의
        
        graph = new int[n+1][n+1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i==j) continue;
                graph[i][j] = 100001 * n;
            }
        }
        for(int i = 0; i < fares.length; i++) {
            graph[fares[i][0]][fares[i][1]] = fares[i][2];
            graph[fares[i][1]][fares[i][0]] = fares[i][2];
        }
        
        if(LOG) printGraph();
        
        floyd(graph, n);
        
        if(LOG) printGraph();
        
        for(int i = 1; i <= n; i++) {
            answer = Math.min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
        }
        
        return answer;
    }
    
    public static void floyd(int[][] graph, int n) {
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    
    public static void printGraph() {
        for(int[] gra: graph) {
            for(int g: gra) {
                System.out.print(g+"\t");
            }
            System.out.println();
        }
        System.out.println();
    }
}