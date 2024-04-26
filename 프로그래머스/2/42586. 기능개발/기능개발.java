import java.util.*;

class Solution {
    static boolean LOG = false;
    
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        
        int cnt;
        int pos = 0;
        
        ArrayList<Integer> list = new ArrayList<>();
        
        // 진행 상황 업데이트
        while(pos < progresses.length) {
            cnt = 0;
            
            if(progresses[pos] >= 100) {
                if(LOG) System.out.println("pos : " + pos);
                for(int i = pos; i < progresses.length; i++) {
                    if(progresses[i] < 100) {
                        break;
                    }
                    if(LOG) System.out.println("pos : " + i);
                    cnt++;
                    pos++;
                }
                list.add(cnt);
            }
            
            for(int i = pos; i < progresses.length; i++) {
                progresses[i] += speeds[i];
            }
        }
        
        answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}