import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");
        
        Stack<String> stack = new Stack<>();
        stack.push(Character.toString(s.charAt(0)));
        for(int i = 1; i < s.length(); i++) {
            if(stack.empty() == false && stack.peek().equals("(") && s.charAt(i) == ')') {
                stack.pop();
            } else {
                stack.push(Character.toString(s.charAt(i)));
            }
        }

        answer = stack.empty() ? true : false;
        
        return answer;
    }
}