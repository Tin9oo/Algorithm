import java.io.*;
import java.util.*;

class Solution {
    static int cnt = 0;
    
    public int solution(int n, int[] money) {
        int answer = 0;
        
        // dfs(0, n, money, 0, 0, new ArrayList<>());
        // answer = cnt;
        
        // dp로 풀어야겠다. (효울성)
        Arrays.sort(money);
        
        int[] dp = new int[n+1];
        dp[0] = 1;
    
        for(int i = 0; i < money.length; i++) {
            for(int j = 1; j <= n; j++) {
                if(j-money[i] < 0) continue;
                
                dp[j] += dp[j - money[i]];
                dp[j] %= 1000000007;
            }
            // System.out.println(Arrays.toString(dp));
        }        
        
        answer = dp[n];
        
        return answer;
    }
    
    static void dfs(int level, int n, int[] money, int idx, int total, ArrayList<Integer> log) {
        if(level >= n || total >= n) {
            if(total == n) {
                // System.out.println(Arrays.toString(log.toArray()));
                cnt++;
                cnt %= 1000000007;
                
            }
            return;
        }
        
        for(int i = idx; i < money.length; i++) {
            log.add(money[i]);
            dfs(level+1, n, money, i, total+money[i], log);
            log.remove(log.size()-1);
        }
    }
}