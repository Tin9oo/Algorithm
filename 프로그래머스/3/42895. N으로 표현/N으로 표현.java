import java.util.*;

class Solution {
    public int solution(int N, int number) {
        int answer = -1;
        
        if(N == number) {
            return 1;
        }
        
        // dp 배열 초기화
        // 행 : '행' 개의 숫자를 사용하는 경우
        // 열 : 현재 숫자 개수에서 가능한 연산 결과 <- 괄호라고 생각하면 쉬울 듯.
        ArrayList<Set<Integer>> dp = new ArrayList<>();
        for(int i = 0; i <= 8; i++) {
            dp.add(new HashSet<>());
        }
        
        // 초기값 추가
        dp.get(1).add(N);
        
        // 사용하는 숫자 수를 늘려가며 반복
        for(int i = 2; i <= 8; i++) {
            // 숫자를 그냥 붙이는 경우
            StringBuilder sb = new StringBuilder();
            sb.append(N);
            for(int j = 1; j < i; j++) {
                sb.append(N);
            }
            dp.get(i).add(Integer.valueOf(sb.toString()));
            
            // 사칙연산을 하는 경우
            for(int j = 1; j < i; j++) {
                int k = i - j;
                
                for(Integer num1: dp.get(j)) {
                    for(Integer num2: dp.get(k)) {
                        dp.get(i).add(num1 + num2);
                        dp.get(i).add(num1 - num2);
                        dp.get(i).add(num1 * num2);
                        if(num2 != 0) {
                            dp.get(i).add(num1 / num2);                            
                        }
                    }
                }
            }
            
            // 결과 중에 정답이 있는지 판단
            if(dp.get(i).contains(number)) {
                return i;
            }
        }
        
        return answer;
    }
}