import java.util.*;

class Solution {
    static final boolean LOG = false;
    
    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        
        // 도착지점 바위 추가
        int[] tmpRocks = new int[rocks.length+1];
        System.arraycopy(rocks, 0, tmpRocks, 0, rocks.length);
        tmpRocks[tmpRocks.length-1] = distance;
        rocks = tmpRocks;
        
        Arrays.sort(rocks);
                
        if(LOG) {
            for(int r: rocks) System.out.print(r+" ");
            System.out.println();
            System.out.println();
        }
        
        int left = 1;
        int right = distance;
        
        int mid = 0;
        int curPos = 0;
        
        int cnt;
                
        while(left <= right) {
            cnt = 0; curPos = 0;
            mid = (left + right) / 2;
            
            if(LOG) System.out.println("left="+left+", right="+right+", mid="+mid);
            
            for(int rock: rocks) {
                if(rock-curPos >= mid) {
                    curPos = rock;
                } else {
                    // 마지막 바위를 처리하며, 도착지와의 거리가 m보다 작더라도 이분탐색의 조건에 맞지 않기 때문에 유효하지 않은 정답이다.
                    cnt++;
                }
                if(LOG) System.out.println("curPos="+curPos+", rock="+rock+", cnt="+cnt);
            }
                        
            if(cnt <= n) {
                left = mid + 1;
                answer = mid;
            } else {
                right = mid - 1;
            }
            
            if(LOG) System.out.println();
        }
                
        return answer;
    }
}