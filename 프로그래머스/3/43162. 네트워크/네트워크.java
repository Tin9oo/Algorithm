import java.util.*;

class Solution {
    static int[] visited;
        
    static int cnt = 0;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        visited = new int[n];
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == 1) continue;
            visited[i] = 1;
            cnt++;
            bfs(n, computers, i);
        }
        
        answer = cnt;
        
        return answer;
    }
    
    public static void bfs(int n, int[][] computers, int idx) {        
        Queue<Integer> q = new LinkedList<>();
        
        q.add(idx);
        
        while(q.isEmpty() == false) {
            Integer pos = q.poll();
            
            for(int i = 0; i < n; i++) {
                if(pos == i) continue;
                if(computers[pos][i] == 0) continue;
                if(visited[i] == 1) continue;
                
                visited[i] = 1;
                q.add(i);
            }
            
        }
    }
}