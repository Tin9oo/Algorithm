import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        
        int a = 0;
        int b = 0;
        
        int cnt = 0;
        
        for(int scov: scoville) {
            pq.add(scov);
        }
        
        while(pq.peek() < K) {
            if(pq.size() == 1) {
                cnt = -1;
                break;
            }
            a = pq.poll();
            b = pq.poll();
            
            pq.add(a+b*2);
            
            cnt++;
        }
        
        answer = cnt;
        
        return answer;
    }
}