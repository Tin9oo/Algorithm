import java.util.*;

/*
    [접근1]
    반복문으로 탐색한다. 이때, (limit - 현재값)에 가장 근사하면서 작은 값을 찾아서 같이 보트로 보낸다.
    대상 값이 복수개일 수 있다.
    
    정렬하면? 양 끝에서 투포인터로 보트 태울 수 있을듯?
    1 2 3 4 5
    
    [접근2]
    ArrayList에 담는다.
    people에서 하나씩 담는다.
    limit 초과하면 다음 자리에 담는다.
    
    [접근3]
    Deque에 정렬된 채로 담는다.
    큰애 하나 빼고 작은애를 꽉 찰 때 까지 담는다.
    Deque 다 빌 때 까지 반복
    
    ---
    
    2중 반복은 N^2 => 25억
    NlogN => 25만
*/

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
        
        Deque<Integer> boats = new ArrayDeque<>();
        for(int person: people) boats.add(person);
        
        while(!boats.isEmpty()) {
            int boat = boats.removeLast();
            
            if(!boats.isEmpty() && boat+boats.getFirst() <= limit) {
                boat+=boats.removeFirst();
            }
            
            answer++;
        }
        
        return answer;
    }
}