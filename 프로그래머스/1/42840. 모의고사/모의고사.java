import java.util.*;

class Solution {
    static int[][] pick = {
        {1, 2, 3, 4, 5}, 
        {2, 1, 2, 3, 2, 4, 2, 5}, 
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    public int[] solution(int[] answers) {
        int[] answer = {};
        
        int[] score = {0, 0, 0};
        
        int idx = 0;
        for(int ans: answers) {
            for(int i = 0; i < 3; i++) {
                if(pick[i][idx%pick[i].length] == ans) {
                    score[i]++;
                }
            }
            
            idx++;
        }
        
        int max = Arrays.stream(score).max().getAsInt();
        ArrayList<Integer> arr = new ArrayList<>();
        
        for(int i = 0; i < 3; i++) {
            if(max == score[i]) {
                arr.add(i+1);
            }
        }
        
        answer = arr.stream().mapToInt(i -> i).toArray();
        
        return answer;
    }
}