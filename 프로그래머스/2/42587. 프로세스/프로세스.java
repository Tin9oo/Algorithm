import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        Queue<Integer> q = new LinkedList<>();
        for(int i: priorities) {
            q.add(i);
        }
        
        int pointer = priorities.length - 1; // 최댓값 확인
        Arrays.sort(priorities);
        
        while(!q.isEmpty()) {
            if(q.peek() == priorities[pointer]) {
                q.poll();
                pointer--;
                answer++;
                if(location == 0) {
                    break;
                } else {
                    location--;
                }
            } else {
                q.add(q.poll());
                location--;
                location = location < 0 ? q.size() - 1 : location;
            }
        }
        
        return answer;
    }
}