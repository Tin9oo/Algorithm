import java.util.*;

class Solution {
    static int maxScore = 0;
    
    int solution(int[][] land) {
        int answer = 0;

        // dfs 풀이
//         dfs(land, 0, -1, 0);
        
        // dp 풀이
        int[][] dp = new int[land.length][land[0].length];
        
        for(int i = 0; i < land[0].length; i++) {
            dp[0][i] = land[0][i];
        }
        
        for(int i = 1; i < land.length; i++) {
            for(int j = 0; j < land[0].length; j++) {
                for(int k = 0; k < land[0].length; k++) {
                    if(j == k) continue;
                    dp[i][j] = Math.max(dp[i][j], land[i][j] + dp[i-1][k]);
                }
            }
        }
        
        for(int i = 0; i < land[0].length; i++) {
            maxScore = Math.max(maxScore, dp[land.length-1][i]);
        }
        
        // 결과
        answer = maxScore;
        
        return answer;
    }
    
    static void dfs(int[][] land, int level, int curCol, int score) {
        if(level >= land.length) {
            maxScore = maxScore  > score ? maxScore : score;
            return;
        }
        
        for(int i = 0; i < land[level].length; i++) {
            if(i == curCol) continue;
            
            dfs(land, level + 1, i, score + land[level][i]);
        }
    }
}