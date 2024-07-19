import java.io.*;
import java.util.*;

class Solution {
    // 테이블 위 블록에 해당하는 이동 방향을 순서대로 저장합니다.
    // 이동 방향을 숫자로 저장하면 ++ 연산을 통해 이동 방향을 회전시킬 수 있습니다.
    // 시작지점에 따라 정답이 안나올 수도 있으므로 (폐기)
    
    static int N;
    static boolean[][] vis;
    
    public int solution(int[][] game_board, int[][] table) {
        int answer = -1;
        
        N = game_board.length;
        vis = new boolean[N][N];
        
        List<List<int[]>> emptySpaces = new ArrayList<>();
        List<List<int[]>> puzzlePices = new ArrayList<>();
        
        // 빈 공간 추출
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(game_board[i][j] == 1 || vis[i][j] == true) continue;
                emptySpaces.add(bfs(game_board, i, j, 0));
            }
        }
        
        // 퍼즐 조각 추출
        vis = new boolean[N][N];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(table[i][j] == 0 || vis[i][j] == true) continue;
                puzzlePices.add(bfs(table, i, j, 1));
            }
        }
        
        // printState(emptySpaces, puzzlePices);
        
        // 맞추기
        int cnt = 0;
        
        for(int j = 0; j < emptySpaces.size(); j++) {
            List<int[]> space = emptySpaces.get(j);
            
            if(space == null) continue;
            
            for(int i = 0; i < puzzlePices.size(); i++) {
                List<int[]> pice = puzzlePices.get(i);
                
                boolean alreadyFound = false;
                
                if(pice == null) continue;
                
                for(int rot = 0; rot < 4; rot++) {
                    if(canFit(space, pice)) {                        
                        cnt += pice.size();
                        puzzlePices.set(i, null);
                        emptySpaces.set(j, null);
                        
                        // for(int[] cell: pice) {
                        //     System.out.print("("+cell[0]+", "+cell[1]+"), ");
                        // }
                        // System.out.println(" is out !!");
                        
                        alreadyFound = true;
                        break;
                    }
                    pice = rotate(pice);
                }
                
                if(alreadyFound) break;
            }
        }
        
        answer = cnt;
        
        return answer;
    }
    
    static List<int[]> bfs(int[][] map, int r, int c, int target) {
        int[] dr = {-1, 0, 1, 0};
        int[] dc = {0, 1, 0, -1};
        
        List<int[]> shape = new ArrayList<>();
        
        Queue<int[]> q = new LinkedList<>(); 
        
        vis[r][c] = true;
        q.add(new int[] {r, c});
        
        while(!q.isEmpty()) {
            int[] node = q.poll();
            r = node[0];
            c = node[1];
            
            shape.add(new int[] {r, c});
            
            for(int i = 0; i < dr.length; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nc < 0 || N <= nr || N <= nc) continue;
                if(vis[nr][nc] == true) continue;
                if(map[nr][nc] != target) continue;
                
                vis[nr][nc] = true;
                q.add(new int[] {nr, nc});
            }
        }
        
        return normalize(shape);
    }
    
    static boolean canFit(List<int[]> space, List<int[]> pice) {
        if(space.size() != pice.size()) return false;
        
        for(int i = 0; i < space.size(); i++) {
            if(space.get(i)[0] == pice.get(i)[0] && space.get(i)[1] == pice.get(i)[1]) continue;
            
            return false;
        }
        
        return true;
    }
    
    static List<int[]> rotate(List<int[]> shape) {
        List<int[]> newShape = new ArrayList<>();
        
        for(int[] cell: shape) {
            newShape.add(new int[] {cell[1], -cell[0]});
        }
        
        return normalize(newShape);
    }
    
    static List<int[]> normalize(List<int[]> shape) {
        Collections.sort(shape, (a, b) -> {
            if(a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });
        
        int minR = shape.get(0)[0];
        int minC = shape.get(0)[1];
        
        List<int[]> normalized = new ArrayList<>();
        for(int[] cell: shape) {
            normalized.add(new int[] {cell[0] - minR, cell[1] - minC});
        }
        
        return normalized;
    }
    
    static void printState(List<List<int[]>> emptySpaces, List<List<int[]>> puzzlePices) {
        System.out.println("emptySpaces !!");
        for(List<int[]> space: emptySpaces) {
            if(space == null) continue;
            for(int[] cell: space) {
                System.out.print("("+cell[0]+", "+cell[1]+"), ");
            }
            System.out.println();
        }
        System.out.println();
        
        System.out.println("puzzlePices !!");
        for(List<int[]> space: puzzlePices) {
            if(space == null) continue;
            for(int[] cell: space) {
                System.out.print("("+cell[0]+", "+cell[1]+"), ");
            }
            System.out.println();
        }
        System.out.println();
    }
}