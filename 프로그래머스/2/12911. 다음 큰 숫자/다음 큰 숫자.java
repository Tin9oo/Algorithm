import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;

        String str = Integer.toBinaryString(n++);
        
        int origin = cntBinaryOne(str);
        
        while(true) {
            int cnt = cntBinaryOne(Integer.toBinaryString(n++));
            if(origin == cnt) {
                answer = n-1;
                break;
            }
        }
        
        return answer;
    }
    
    static int cntBinaryOne(String target) {
        int cnt = 0;
        
        for(int i = 0; i < target.length(); i++) {
            if(target.charAt(i) == '1') cnt++;
        }
        
        return cnt;
    }
}