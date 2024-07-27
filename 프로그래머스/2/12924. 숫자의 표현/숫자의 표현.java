import java.io.*;
import java.util.*;

class Solution {
    public int solution(int n) {
        // 풀이 1
//         int answer = 0;
        
//         for(int i = 1; i <= n; i++) {
//             int tmp = 0;
//             for(int j = 0; j < n; j++) {
//                 if(tmp+i+j > n) break;
//                 else if(tmp+i+j == n) answer++;
//                 tmp += i+j;
//             }
//         }
        
//         return answer;
        
        // 풀이 2

        int count = 0;
        
        // k는 연속된 자연수의 개수
        for (int k = 1; k * (k + 1) / 2 <= n; k++) {
            // n이 k개의 연속된 자연수의 합으로 표현될 수 있는지 확인
            if ((n - k * (k + 1) / 2) % k == 0) {
                count++;
            }
        }
        
        return count;
    }
}