import java.io.*;
import java.util.*;

class Solution {
    static int[] discount = new int[]{10, 20, 30, 40};
    
    static int plus = 0;
    static int income = 0;
    
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = {};
        
        int[][] prices = new int[emoticons.length][2];
        
        dfs(0, users, emoticons, prices);
        
        answer = new int[]{plus, income};
        
        return answer;
    }
    
    static void dfs(int lev, int[][] users, int[] emos, int[][] prices) {
        if(lev >= emos.length) {
            calc(users, prices);
            
            return;
        }
        
        for(int i = 0; i < discount.length; i++) {
            prices[lev][0] = discount[i];
            prices[lev][1] = emos[lev];
            dfs(lev+1, users, emos, prices);   
        }
    }
    
    static void calc(int[][] users, int[][] prices) {
        // System.out.println("calc() !!");
        int plus2 = 0;
        int income2 = 0;
        
        for(int[] u: users) {
            // System.out.println("u: " + Arrays.toString(u));
            int tot = 0;
            
            for(int[] p: prices) {
                if(p[0] < u[0]) continue;
                // System.out.println("p: " + Arrays.toString(p));
                
                tot += (p[1] * (100 - p[0]))/100;
                // 기존 코드는 p[0]에 나누기 100.0을 진행하고 마지막에 int로 캐스팅합니다.
                // 이 경우 통과하지 못하고, int 캐스팅을 제거하면 통과합니다.
                // 정확도 때문이라기엔 (int) 로 캐스팅하지 않는 경우에 오차가 발생할테니 말이 안되고
                // 뭐가 문제인지 모르겠습니다.
            }
            
            if(tot >= u[1]) plus2++;
            else income2 += tot;
        }
        
        // System.out.println("plus2: " + plus2 + ", income2: " + income2);
        
        if(plus < plus2) {
            plus = plus2;
            income = income2;
        } else if (plus == plus2) {
            if(income < income2) {
                income = income2;
            }
        }
    }
}