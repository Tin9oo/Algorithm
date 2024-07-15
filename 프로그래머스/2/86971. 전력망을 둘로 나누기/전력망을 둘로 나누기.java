import java.util.*;
import java.io.*;

class Solution {
    static int ans = Integer.MAX_VALUE;
    
    public int solution(int n, int[][] wires) {
        int answer = -1;
        
        boolean[][] map = new boolean[n+1][n+1];
        int cnt;
                
        for(int i = 0; i < wires.length; i++) {
            initMap(n, i, wires, map);
            cnt = bfs(n, map);
            if(ans > cnt) {
                ans = cnt;
            }
        }
        
        return ans;
    }
    
    private static void initMap(int n, int num, int[][] wires, boolean[][] map) {
        for(boolean[] row: map) { // 배열 초기화를 하지 않고 새 객체를 담게 되면, 원본과의 연결이 끊어지게 된다.
            Arrays.fill(row, false);
        }
        
        for(int i = 0; i < wires.length; i++) {
            // if(i == num) System.out.println("cut: " + Arrays.toString(wires[i]));
            if(i == num) continue;
            
            int[] wire = wires[i];
            map[wire[0]][wire[1]] = true;
            map[wire[1]][wire[0]] = true;
        }
        
        // System.out.println("map");
        // for(boolean[] ma: map) System.out.println(Arrays.toString(ma));
    }
                
    private static int bfs(int n, boolean[][] map) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] vis = new boolean[n+1];
        int cnt = 0;
        // System.out.println("vis: " + Arrays.toString(vis));
        
        vis[1] = true;
        q.offer(1);
        cnt++;
        
        while(!q.isEmpty()) {
            Integer node = q.poll();
            // System.out.println("node: " + node);
            
            for(int i = 1; i <= n; i++) {
                if(vis[i]) continue;
                if(node == i) continue;
                // System.out.println("map[node][i]: " + map[node][i]);
                if(!map[node][i]) continue;
                // System.out.println("\ti: " + i);
                
                vis[i] = true;
                q.offer(i);
                cnt++;
            }
        }
    
        return Math.abs(n - cnt - cnt);
    }
}