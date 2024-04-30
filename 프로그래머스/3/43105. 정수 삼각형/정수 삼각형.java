import java.util.*;

class Solution {
    public static final boolean LOG = false;
    
    public int solution(int[][] triangle) {
        int answer = 0;
        
        int[][] dp = new int[triangle.length][triangle[triangle.length-1].length];
        
        dp[0][0] = triangle[0][0];
        
        for(int i = 1; i < triangle.length; i++) {
            for(int j = 0; j < triangle[i].length; j++) {
                for(int k = j - 1; k <= j; k++) {
                    if(k < 0) continue;
                    if(dp[i][j] < dp[i-1][k] + triangle[i][j]) {
                        dp[i][j] = dp[i-1][k] + triangle[i][j];                    
                    }
                }
            }
            if(LOG) printDp(dp);
        }
        
        for(int i = 0; i < triangle[triangle.length - 1].length; i++) {
            answer = Math.max(answer, dp[triangle.length-1][i]);
        }
        
        return answer;
    }
    
    public static void printDp(int[][] dp) {
        for(int[] arr: dp) {
            for(int ele: arr) {
                System.out.print(ele + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}