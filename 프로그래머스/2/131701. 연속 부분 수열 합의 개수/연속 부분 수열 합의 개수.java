import java.util.*;

class Solution {
    public int solution(int[] elements) {
        int answer = 0;
        
        int len = elements.length;
        Set<Integer> s = new HashSet<>();
        
        // 부분 수열의 길이에 따른 각각의 합
        for(int i = 1; i <= len; i++) { // 부분 수열의 길이
            for(int j = 0; j < len; j++) { // 부분 수열의 시작 인덱스
                int sum = 0;
                for(int k = 0; k < i; k++) { // 부분 수열 탐색
                    int idx = (j + k) % len;
                    
                    sum += elements[idx];
                }
                
                s.add(sum);
            }
        }
        
        answer = s.size();
        
        return answer;
    }
}