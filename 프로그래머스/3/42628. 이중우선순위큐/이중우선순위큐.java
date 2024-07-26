import java.util.*;

class Solution {
    // pq말고 deque로 구현하는게 나으려나?
    // 그런데 아마 정렬 비용이 클 거같다.
    public int[] solution(String[] operations) {
        int[] answer = {0, 0};
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(String op: operations) {
            String[] opSplit = op.split(" ");
            String command = opSplit[0];
            Integer num = Integer.valueOf(opSplit[1]);
            
            if(command.equals("I")) {
                pq.add(num);
            } else if(!pq.isEmpty()) {
                if(num == -1) {
                    pq.remove();
                }
                else if(num == 1) {
                    PriorityQueue<Integer> tmpPq = new PriorityQueue<>(Comparator.reverseOrder());
                    tmpPq.addAll(pq);
                    tmpPq.remove();
                    pq.clear();
                    pq.addAll(tmpPq);
                } 
            }
        }
        
        PriorityQueue<Integer> tmpPq = new PriorityQueue<>(Comparator.reverseOrder());
        tmpPq.addAll(pq);
        
        if(!pq.isEmpty()) {
            answer[0] = tmpPq.peek();
            answer[1] = pq.peek();
        }
        
        return answer;
    }
}