import java.util.*;

class Solution {
    static int maxVal = 0;
    
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        int[] stud = new int[n];
        Arrays.fill(stud, 1);
        for(int res: reserve) {
            stud[res-1] = 2;
        }
        for(int los: lost) {
            if(stud[los-1] > 0) stud[los-1]--;
        }
        
//         dfs(0, stud);
        
//         return maxVal;
        
        for(int i = 0; i < n; i++) {
            if(stud[i] != 2) continue;
            
            int dir = 0;
            if(i-1 >= 0 && stud[i-1] == 0) dir--;
            if(i+1 < n && stud[i+1] == 0) dir++;
            
            if(dir == -1) {
                stud[i+dir]++;
                stud[i]--;
            } else if (dir == 1) {
                stud[i+dir]++;
                stud[i]--;
            }
            // for(int a: stud) System.out.print(a+" ");
            // System.out.println();
        }
        
        for(int i = 0; i < n; i++) {
            if(stud[i] != 2) continue;
            
            if(i-1 >= 0 && stud[i-1] == 0) {
                stud[i-1]++;
                stud[i]--;
            } else if(i+1 < n && stud[i+1] == 0) {
                stud[i+1]++;
                stud[i]--;
            }
            // for(int a: stud) System.out.print(a+" ");
            // System.out.println();
        }
        
        for(int c: stud) {
            if(c > 0) answer++;
        }
        
        return answer;
    }
    
    public static void dfs(int idx, int[] arr) {
        // System.out.println("dfs(idx="+idx+")");
        // for(int a: arr) System.out.print(a+" ");
        // System.out.println();
        
        if(idx >= arr.length) {
            int cnt = 0;
            for(int a: arr) {
                if(a>0) cnt++;
            }
            maxVal = Math.max(maxVal, cnt);
            return;
        }
        
        if(arr[idx] == 2 && idx-1 >= 0 && arr[idx-1] == 0) {
            int[] tmpArr = Arrays.copyOf(arr, arr.length);
            tmpArr[idx-1]++;
            tmpArr[idx]--;
            dfs(idx+1, tmpArr);
        } else {
            dfs(idx+1, arr);            
        }

        if(arr[idx] == 2 && idx+1 < arr.length && arr[idx+1] == 0) {
            int[] tmpArr = Arrays.copyOf(arr, arr.length);
            tmpArr[idx+1]++;
            tmpArr[idx]--;
            dfs(idx+1, tmpArr);
        } else {
            dfs(idx+1, arr);
        }
    }
}