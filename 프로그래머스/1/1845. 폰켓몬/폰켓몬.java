import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        Map<Integer, Integer> m = new HashMap<>();
        
        for(int i: nums) {
            m.put(i, m.getOrDefault(i, 0) + 1);
        }
        
        for(Integer keys: m.keySet()) {
            answer++;
        }
        
        if(answer > nums.length / 2) answer = nums.length / 2;
        
        return answer;
    }
}