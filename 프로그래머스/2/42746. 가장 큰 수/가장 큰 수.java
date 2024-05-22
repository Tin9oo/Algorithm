import java.util.*;

class Solution {
    /*
        각 정수의 첫째 수를 정렬해서 내림차순으로 이어붙인다.
        이때, 정렬 후의 인덱스를 가져와서 사용하거나
        정렬을 커스텀해서 사용한다.
        
        위 방법은 3, 34인 경우 판단이 어려워지므로
    */
    
    static final boolean LOG = false;
    
    public String solution(int[] numbers) {
        String answer = "";
        
        ArrayList<String> arr = new ArrayList<>();
        for(Integer n: numbers) arr.add(n.toString());
        
        if(LOG) {
            for(String num: arr) System.out.print(num+" ");
            System.out.println();
        }
        
//         arr.sort((o1, o2) -> {            
//             // 길이 같게 만들기
//             if(o1.length() > o2.length()) {
//                 for(int i = 0; i < o1.length()-o2.length(); i++)
//                     o2+=o2.charAt(i); // 3, 34 그리고 3, 32 같은 경우의 우선순위 파악이 어려우므로 같은 수로 뒤에 붙여서 비교를 알맞게 수행한다.
//             } else if(o1.length() < o2.length()) {
//                 for(int i = 0; i < o2.length()-o1.length(); i++)
//                     o1+=o1.charAt(i);
//             }
            
//             if(LOG) {
//                 System.out.println("o1: "+o1+", o2: "+o2);
//             }
            
//             // 문자열 비교
//             return o2.compareTo(o1);
//         });
        
        arr.sort((o1, o2) -> (o2+o1).compareTo(o1+o2));
        
        if(LOG) {
            for(String num: arr) System.out.print(num+" ");
            System.out.println();
        }
        
        for(String str: arr) answer += str;
        
        if(answer.charAt(0) == '0') answer = "0";
        
        return answer;
    }
}