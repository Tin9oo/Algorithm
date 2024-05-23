import java.util.*;

/*
    한 자리 숫자를 조합해서 '소수' 만들기
    문자열로 숫자가 주어지는데 랜덤으로 어떻게 조합해야하지 ?
    순열 만들어야할거같은데,,
    
    
*/

class Solution {
    public int solution(String numbers) {
        int answer = 0;
        
        // 순열 생성
        TreeSet<Integer> perms = new TreeSet<>();
        for(int i = 1; i <= numbers.length(); i++) {
            perm(numbers, i, 0, new int[numbers.length()], "", perms);
        }
        
        printPerm(perms);
        
        // 소수 판별
        for(Integer num: perms) {
            if(num == 0 || num == 1) continue;
            
            boolean flag = true;
            
            for(int i = 2; i <= num/2; i++) {
                if(num%i == 0) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) answer++;
        }
        
        return answer;
    }
    
    static void perm(String numbers, int num, int level, int[] visited, String str, TreeSet<Integer> perms) {
        if(level >= num) {
            perms.add(Integer.valueOf(str));
            return;
        }
        
        for(int i = 0; i < numbers.length(); i++) {
            if(visited[i] == 1) continue;
            
            visited[i] = 1;
            perm(numbers, num, level+1, visited, str+numbers.charAt(i), perms);
            visited[i] = 0;
        }
    }
    
    static void printPerm(TreeSet<Integer> perms) {
        for(Integer p: perms) {
            System.out.print(p+" ");
        }
        System.out.println();
    }
}