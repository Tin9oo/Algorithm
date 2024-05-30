import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        
        int len = number.length() - k;
        
        Stack<Character> stack = new Stack<>();
                
        for(int i = 0; i < number.length(); i++) {
            char c = number.charAt(i);
            while(stack.isEmpty()==false && k>0 && stack.peek() < c) {
                stack.pop();
                k--;
            }
            stack.add(c);
        }
        
        for(Character ch: stack) {
            answer+=ch;
        }
   
        return answer.substring(0, len);
    }
}