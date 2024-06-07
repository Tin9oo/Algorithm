import java.util.*;

/*
    
*/

class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        for(int i = 1; i <= brown; i++) {
            for(int j = 1; j <= brown; j++) {
                if(i+j-2 != brown/2) continue;
                if(i*j == (brown+yellow)) {
                    answer[0] = i;
                    answer[1] = j;
                }
            }
        }
        
        Arrays.sort(answer);
        int tmp = answer[0];
        answer[0] = answer[1];
        answer[1] = tmp;
        
        return answer;
    }
}