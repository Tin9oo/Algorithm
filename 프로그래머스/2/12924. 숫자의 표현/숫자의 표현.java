import java.io.*;
import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for(int i = 1; i <= n; i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                if(tmp+i+j > n) break;
                else if(tmp+i+j == n) answer++;
                tmp += i+j;
            }
        }
        
        return answer;
    }
}