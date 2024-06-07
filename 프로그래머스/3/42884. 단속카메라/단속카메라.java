import java.util.*;

/*
    차량 수 = 10,000
    총 거리 = 60,000
    n = 10,000 -> n^2 = 100,000,000
    
    1. 모든 위치 탐색하면서 최대로 제거 가능한 위치에 설치하고 해당 차량들 제거
    2. 1번 반복
*/

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        
        int pos;
        
        Arrays.sort(routes, (o1, o2) -> o1[1] - o2[1]);
        // for(int[] route: routes) System.out.println(route[0]+", "+route[1]);
        
        pos = routes[0][1];
        answer++;
        
        for(int[] route: routes) {
            if(pos < route[0]) {
                pos = route[1];
                answer++;
            }
        }
        
        return answer;
    }
}