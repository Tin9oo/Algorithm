import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
        int[] visited = new int[jobs.length];
        
        ArrayList<Integer> al = new ArrayList<>();
        
        int tic = 0;
        
        while(true) {
            if(check(visited) == true && pq.isEmpty()) break;
            
            // 현재 시간에 맞는 프로세스 처리목록에 추가
            for(int i = 0; i < jobs.length; i++) {
                int[] job = jobs[i];
                if(visited[i] == 1) continue;
                if(job[0] > tic) continue;
                
                visited[i] = 1;
                pq.offer(job);
                // System.out.println("Process length "+job[1]+" is offered !!");
            }
            
            // 들어온 프로세스 처리
            if(pq.isEmpty() == false) { // pq가 비어있는지 확인해줘야함
                tic += pq.peek()[1]-1;
                // System.out.println("Process length "+pq.peek()[1]+" is processed !!");
                al.add(tic - pq.peek()[0]+1);
                pq.poll();
            }
            
            tic++;
        }
        
        answer = (int) al.stream().mapToInt(Integer::intValue).summaryStatistics().getAverage();
        
        return answer;
    }
    public static boolean check(int[] visited) {
        for(int vis: visited) {
            if(vis == 0) return false;
        }
        return true;
    }
}