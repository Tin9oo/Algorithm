import java.util.*;

class Solution {
    static ArrayList<ArrayList<Integer>> perm = new ArrayList<>();
    
    public int solution(int k, int[][] dungeons) {
        int answer = 0;
                
        makePerm(dungeons.length, 0, new ArrayList<>());        
        
        int kOrigin = k;
        int maxCnt = 0;
        int cnt = 0;
        for(ArrayList<Integer> pe: perm) {
            k = kOrigin;
            cnt = 0;
            for(Integer p: pe) {
                if(k < dungeons[p][0]) continue;
                k -= dungeons[p][1];
                cnt++;
            }
            maxCnt = Math.max(maxCnt, cnt);
        }
        
        answer = maxCnt;
        
        return answer;
    }
    
    static void makePerm(int n, int level, ArrayList<Integer> arr) {
        if(level >= n) {            
            perm.add(new ArrayList<>(arr));
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(arr.contains(i)) continue;
            arr.add(i);
            makePerm(n, level+1, arr);
            arr.remove(arr.size()-1);
        }
    }
}