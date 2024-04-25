import java.util.*;

class Solution {
    
    public static final boolean LOG = false;
    
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        boolean flag = true;
        
        Arrays.sort(participant);
        Arrays.sort(completion);
        
        if(LOG) printArr(participant);
        if(LOG) printArr(completion);
        
        for(int i = 0; i < completion.length; i++) {
            if(participant[i].equals(completion[i]) == false) {
                answer = participant[i];
                flag = false;
                break;
            }
        }
        
        if(flag == true) {
            answer = participant[participant.length - 1];
        }
        
        return answer;
    }
    
    public static void printArr(String[] str) {
        for(String s: str) {
            System.out.print(s + " ");
        }
        System.out.println();
    }
}