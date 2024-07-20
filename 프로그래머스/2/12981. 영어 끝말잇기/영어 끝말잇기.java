import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];

        Set set = new HashSet<>();
        
        String word = words[0];
        char lastChar = word.charAt(word.length()-1);
        set.add(word);
        
        for(int i = 1; i < words.length; i++) {
            word = words[i];
            
            if(word.charAt(0) != lastChar || set.contains(word)) {
                answer[0] = i%n+1;
                answer[1] = i/n+1;
                
                break;
            }
                
            set.add(word);
            lastChar = word.charAt(word.length()-1);            
        }

        return answer;
    }
}