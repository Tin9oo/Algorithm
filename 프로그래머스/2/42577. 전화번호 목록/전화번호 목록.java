import java.util.*;

class Solution {
    static final boolean LOG = false;
    
    public boolean solution(String[] phone_book) {
        boolean answer = true;
                
        Arrays.sort(phone_book);
        if(LOG) for(String str: phone_book) System.out.print(str + " ");
        
        // 한 번호가 다른 번호의 접두어가 되면 false 반환
        for(int i = 0; i < phone_book.length - 1; i++) {
            if(phone_book[i+1].startsWith(phone_book[i])) {
                answer = false;
                break;
            }
        }
        
        return answer;
    }
}