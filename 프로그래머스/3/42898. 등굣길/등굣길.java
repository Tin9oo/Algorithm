import java.util.*;

/*
    장애물을 피해서 목적지 까지 간다.
    이동 방향은 '우측', '아래'만 가능하다.
    최단 경로의 개수를 1,000,000,007로 나눈 나머지를 return
    
    dfs로 모든 경로를 만들 수도 있겠지만, DP로 풀면 더 효율적인 연산이 가능해 보인다.
    시작 지점으로부터 목적지까지 이동하는데 필요한 최소 경로의 수는 부분 문제로 나눌 수 있다.
    당장 눈앞의 칸까지 이동하는 경우의 수를 구하고 그 다음칸까지 이동하는 경우의 수를 누적한다.
    
*/

class Solution {
    static final boolean LOG = false;
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        
        // dp 배열을 초기화 한다.
        // 0열, 0행의 요소는 최단 경로 수가 1이다.
        // But, 0열과 0행 위에 물웅덩이가 있으면 해당 지점 이후로는 최단 경로 수가 0이다.
        int[][] dp = new int[m+1][n+1];
        dp[1][1] = 1;
        for(int[] pud: puddles) {
            dp[pud[0]][pud[1]] = -1;
        }
        
        if(LOG) printDp(dp);
        
        int d1, d2;
        
        // dp 수행
        // 중간 결과가 너무 커져서 오버플로우가 발생한다.
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(i==1 && j==1) continue;
                if(dp[i][j] == -1) continue;
                
                d1 = dp[i-1][j];
                d2 = dp[i][j-1];
                
                if(d1 != -1 && d2 != -1) dp[i][j] = d1 + d2;
                else if(d1 != -1 && d2 == -1) dp[i][j] = d1;
                else if(d1 == -1 && d2 != -1) dp[i][j] = d2;
                
                dp[i][j] %= 1000000007;
            }
        }
        
        if(LOG) printDp(dp);
        
        // 최단 경로 개수를 1000000007로 나눈 나머지 반환
        answer = dp[m][n] % 1000000007;
        
        return answer;
    }
    
    static void printDp(int[][] dp) {
        for(int[] d: dp) {
            for(int dd: d) {
                System.out.print(dd+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
}