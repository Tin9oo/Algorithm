import java.util.*;

class Solution {
    public int solution(int N, int[][] road, int K) {
        int answer = 0;

        List<int[]>[] graph = initMap(N, road);
        answer = dijkstra(K, N, graph);

        return answer;
    }
    
    static List<int[]>[] initMap(int N, int[][] road) {
        List<int[]>[] graph = new ArrayList[N+1];
        for(int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < road.length; i++) {
            int[] r = road[i];
            
            graph[r[0]].add(new int[]{r[1], r[2]});
            graph[r[1]].add(new int[]{r[0], r[2]});
        }
        
        return graph;
    }
    
    static int dijkstra(int K, int N, List<int[]>[] graph) {
        int[] dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.add(new int[]{1, 0});
        
        while(!pq.isEmpty()) {
            int[] cur = pq.poll();
            int u = cur[0];
            int d = cur[1];
            
            if(d > dist[u]) continue;
            
            for(int[] neighbor: graph[u]) {
                int v = neighbor[0];
                int w = neighbor[1];
                
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.add(new int[]{v, dist[v]});
                }
            }
        }
        
        int cnt = 0;
        for(int i = 1; i <= N; i++) {
            if(dist[i] <= K) {
                cnt++;
            }
        }
        
        return cnt;
    }
}