import java.util.*;

class Solution {
    static int maxSheep = 0;
    
    public int solution(int[] info, int[][] edges) {
        int answer = 0;
        
        List<Integer>[] tree = new ArrayList[info.length];
        for(int i = 0; i < info.length; i++) tree[i] = new ArrayList<>();
        
        for(int[] edge: edges) {
            int parent = edge[0];
            int child = edge[1];
            
            tree[parent].add(child);
            tree[child].add(parent);
        }
        
        boolean[] visited = new boolean[info.length];
        List<Integer> nxtNodes = new ArrayList<>();
        nxtNodes.add(0);
        
        dfs(1, 0, 0, nxtNodes, tree, info, visited);
        
        answer = maxSheep;
        
        return answer;
    }
    
    static void dfs(int sheep, int wolf, int curNode, List<Integer> nxtNodes, List<Integer>[] tree, int[] info, boolean[] visited) {
        if(sheep <= wolf) return;
        
        maxSheep = Math.max(maxSheep, sheep); // 이게 종료조건 안에 있으면 양이 항상 많은 경우에 결과 갱신이 안된다.     
        
        visited[curNode] = true;
        
        List<Integer> newNxtNodes = new ArrayList<>(nxtNodes);
        newNxtNodes.remove(Integer.valueOf(curNode)); // 그냥 int로 넣어버리면, 인덱스로 인식할 수 있다.
        
        for(Integer nxtNode: tree[curNode]) {
            if(visited[nxtNode] == false) newNxtNodes.add(nxtNode);
        }
        
        for(Integer nxtNode: newNxtNodes) {
            if(visited[nxtNode] == true) continue;
            
            int nxtSheep = sheep;
            int nxtWolf = wolf;
            
            if(info[nxtNode] == 0) nxtSheep++;
            else nxtWolf++;
            
            dfs(nxtSheep, nxtWolf, nxtNode, newNxtNodes, tree, info, visited);
        }
        
        visited[curNode] = false;
    }
}