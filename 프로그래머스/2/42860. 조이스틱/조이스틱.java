import java.util.*;

/*
    1234567891011121314151617181920212223242526
    ABCDEFGHIJ K L M N O P Q R S T U V W X Y Z
*/

class Solution {
    public int solution(String name) {
        int answer = 0;
        
        // 연속된 A 인덱스 확인
        int a=0, b=0;
        int maxLen = 0;
        int cnt = 0;
        boolean flag = false;
        int idx_start = 0;
        int idx_end = 0;
        
        for(int i = 0; i < name.length(); i++) {
            if(flag == false && name.charAt(i) == 'A') {
                flag = true;
                a = i;
                b = i;
                cnt++;
            } else if(flag == true && name.charAt(i) == 'A') {
                b = i;
                cnt++;
            } else if(flag == true && name.charAt(i) != 'A') {
                flag = false;
                if(maxLen < cnt) {
                    maxLen = cnt;
                    idx_start = a;
                    idx_end = b;
                }
                cnt = 0;
            }
            
            if(i == name.length()-1) {
                if(flag == true && name.charAt(i) == 'A') {
                    if(maxLen < cnt) {
                        idx_start = a;
                        idx_end = b;
                    }
                }
            }
        }
        
        System.out.println("idx_start="+idx_start+", idx_end="+idx_end);
                
        // 문자 선택 횟수
        for(int i = 0; i < name.length(); i++) {
            answer += Math.min(name.charAt(i) - 'A', 'Z' - name.charAt(i) + 1);
        }
        
        // 이동 횟수
        // 중간에 연속된 A가 있는 경우
        int move = Integer.MAX_VALUE/2;
        if(idx_start==0 && idx_end==0)
            move = name.length()-1;
        else {
            if((idx_start-1)*2 + name.length()-(idx_end+1) >= 0)
                move = Math.min(move, (idx_start-1)*2 + name.length()-(idx_end+1));
            if((name.length() - (idx_end+1))*2 + idx_start-1 >= 0)
                move = Math.min(move, (name.length() - (idx_end+1))*2 + idx_start-1);
        }
        if(move == Integer.MAX_VALUE/2) move = 0;
        
        // 한 방향으로 이동하는 경우
        cnt = 0;
        for(int i = name.length()-1; i >= 0; i--) {
            if(name.charAt(i) == 'A') cnt++;
            else break;
        }
        if(cnt != 0 && name.length() - cnt - 1 >= 0)
            move = Math.min(move, name.length() - cnt - 1);

        move = Math.min(move, name.length() - 1);
        
        System.out.println("move="+move);

        // 결과
        answer += move;
        
        return answer;
    }
}