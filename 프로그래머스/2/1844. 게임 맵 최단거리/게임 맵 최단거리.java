import java.util.*;

class Solution {
    static class Node {
        int r;
        int c;
        
        Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};
    
    public int solution(int[][] maps) {
        int answer = -1;
        
        int[][] log = bfs(maps);
        
        answer = log[maps.length-1][maps[0].length-1];
        
        return answer;
    }
    
    static int[][] bfs(int[][] maps) {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0));
        
        int[][] log = new int[maps.length][maps[0].length];
        log[0][0] = 1;
        log[maps.length-1][maps[0].length-1] = -1;
        
        while(q.isEmpty() == false) {
            // printData(maps, log);
            
            Node node = q.poll();
            
            // 목표 도달 시 종료
            if(log[maps.length-1][maps[0].length-1] > 0) return log;
            
            for(int i = 0; i < dr.length; i++) {
                Node nn = new Node(node.r+dr[i], node.c+dc[i]);
                
                if(nn.r<0 || nn.c<0 || maps.length<=nn.r || maps[0].length<=nn.c) continue;
                if(log[nn.r][nn.c] > 0) continue;
                if(maps[nn.r][nn.c] == 0) continue;
                
                log[nn.r][nn.c] = log[node.r][node.c] + 1;
                q.offer(nn);
            }
        }
        
        return log;
    }
    
    static void printData(int[][] maps, int[][] log) {
        for(int i = 0; i < maps.length; i++) {
            for(int j = 0; j < maps[0].length; j++) {
                System.out.print(maps[i][j]+"("+log[i][j]+")\t");
            }
            System.out.println();
        }
        System.out.println();
    }
}