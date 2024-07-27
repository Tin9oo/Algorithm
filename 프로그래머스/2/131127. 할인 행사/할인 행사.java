import java.io.*;
import java.util.*;

class Solution {
    static final int MAX_DAYS = 10;
    
    static int cnt = 0;
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        List<String> wan = new ArrayList<>();
        for(String w: want) wan.add(w);
        List<Integer> num = new ArrayList<>();
        for(Integer n: number) num.add(n);
        List<Integer> tmp = new ArrayList<>(number.length); // 초기값 0으로 초기화
        for(int i = 0; i < number.length; i++) tmp.add(0);
        
        for(int i = 0; i < MAX_DAYS; i++) {
            int idx = wan.indexOf(discount[i]);
            if(idx != -1) tmp.set(idx, tmp.get(idx)+1);
        }
        // System.out.println("tmp: " + tmp.toString());
        
        // 초기 상태로 검사.
        if(check(num, tmp)) cnt++;
        
        // 1일부터 검사
        for(int i = 0; i < discount.length - MAX_DAYS; i++) {
            int front = i;
            int end = front + MAX_DAYS;
            
            int idx = wan.indexOf(discount[front]);
            if(idx != -1) tmp.set(idx, tmp.get(idx)-1);
            
            idx = wan.indexOf(discount[end]);
            if(idx != -1) tmp.set(idx, tmp.get(idx)+1);
            
            // System.out.println("tmp: " + tmp.toString());
            
            if(check(num, tmp)) cnt++;
        }
        
        answer = cnt;
        
        return answer;
    }
    
    static boolean check(List<Integer> num, List<Integer> tmp) {
        for(int i = 0; i < num.size(); i++) {
            if(num.get(i) != tmp.get(i)) return false;
        }
        return true;
    }
}