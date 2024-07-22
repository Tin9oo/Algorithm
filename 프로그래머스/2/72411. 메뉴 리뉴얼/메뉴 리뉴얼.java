import java.io.*;
import java.util.*;

class Solution {
    public String[] solution(String[] orders, int[] course) {
        String[] answer = {};
        
        Arrays.sort(orders, (a, b) -> a.length() - b.length());
        
        // course 대상 개수에 해당하는 조합을 우선 뽑는다.
        Map<String, Integer> hmap = new HashMap<>();
        for(int i = 0; i < orders.length; i++) {
            char[] charArr = orders[i].toCharArray();
            Arrays.sort(charArr);
            for(int j = 0; j < course.length; j++) {
                combi(charArr, 0, course[j], new StringBuilder(), hmap);
            }
        }
        
        // 전체 주문 중, 몇번 나왔는지 검색한다.
        List<String> result = new ArrayList<>();
        for(int len: course) {
            int maxCnt = 2;
            List<String> tmpList = new ArrayList<>();
            
            for(Map.Entry<String, Integer> entry: hmap.entrySet()) {
                if(entry.getKey().length() == len && entry.getValue() >= maxCnt) {
                    if(maxCnt < entry.getValue()) {
                        maxCnt = entry.getValue();
                        tmpList.clear();
                    }
                    tmpList.add(entry.getKey());
                }
            }
            
            result.addAll(tmpList);
        }
        
        answer = new String[result.size()];
        for(int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        Arrays.sort(answer);
        
        return answer;
    }
    
    static void combi(char[] order, int start, int len, StringBuilder sb, Map<String, Integer> hmap) {
        if(sb.length() == len) {
            hmap.put(sb.toString(), hmap.getOrDefault(sb.toString(), 0) + 1);
            return;
        }
        
        for(int i = start; i < order.length; i++) {
            sb.append(order[i]);
            combi(order, i+1, len, sb, hmap);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}