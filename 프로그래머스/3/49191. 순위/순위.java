import java.util.*;

class Solution {    
    public int solution(int n, int[][] results) {
        int answer = 0;
                
        int[][] graph = new int[n+1][n+1];
        for(int i = 0; i < graph.length; i++) {
            Arrays.fill(graph[i], 0);
        }
        
        for(int[] res: results) {
            graph[res[0]][res[1]] = 1;
            graph[res[1]][res[0]] = -1;
        }
        
        // printGraph(graph);
        
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(i==j) continue;
                    if(graph[i][j] != 0) continue;
                    // graph[i][j] = Math.max(graph[i][j], graph[i][k] + graph[k][j]);
                    if(graph[i][k] + graph[k][j] != 0) {
                        graph[i][j] = (graph[i][k] + graph[k][j]) / 2;
                    }
                }
            }
        }
        
        // printGraph(graph);
        
        for(int[] gra: graph) {
            int cnt = 0;
            for(int g: gra) {
                if(g != 0) cnt++;
            }
            if(cnt == n-1) answer++;
        }
        
        return answer;
    }
    
    static void printGraph(int[][] graph) {
        for(int[] gra: graph) {
            for(int g: gra) {
                System.out.print(g+"\t");
            }
            System.out.println();
        }
        System.out.println();
    }
}