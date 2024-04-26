import java.util.*;

public class Solution {
    static boolean LOG = false;
    
    public int[] solution(int []arr) {
        int[] answer = {};
        
        Stack<Integer> stack = new Stack<>();
        
        stack.push(arr[0]);
        if(LOG) System.out.println(arr[0] + " is pushed !!");
        for(int i = 1; i < arr.length; i++) {
            if(stack.peek() == arr[i]) continue;
            stack.push(arr[i]);
            if(LOG) System.out.println(arr[i] + " is pushed !!");
        }
        
        answer = new int[stack.size()];
        for(int i = stack.size() - 1; i >= 0; i--) {
            answer[i] = stack.peek();
            stack.pop();
        }

        return answer;
    }
}