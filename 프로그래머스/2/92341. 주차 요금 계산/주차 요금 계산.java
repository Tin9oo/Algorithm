import java.util.*;

class Solution {
    static Map<String, int[]> map = new HashMap<>();

    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        ArrayList<Integer> costArr = new ArrayList<>();
        Map<String, Integer> costMap = new HashMap<>();
        Map<String, Integer> elapseMap = new HashMap<>();
        
        for(String rec: records) {
            String time, num, op;
            String[] sArr = rec.split(" ");
            time = sArr[0]; num = sArr[1]; op = sArr[2];
            
            mapping(time, num, op);
            
            if(!op.equals("OUT")) continue;
            
            int elapse = map.get(num)[1] - map.get(num)[0];
            
            elapseMap.put(num, elapseMap.getOrDefault(num, 0) + elapse);
            map.remove(num);
        }
        
        // 입차 후 출차 기록이 없는 차량 처리
        for(Map.Entry<String, int[]> entry: map.entrySet()) {
            int elapse = (23 * 60 + 59) - entry.getValue()[0];
            elapseMap.put(entry.getKey(), elapseMap.getOrDefault(entry.getKey(), 0) + elapse);
        }
        
        // 누적 시간 요금 일괄 계산
        for(Map.Entry<String, Integer> entry: elapseMap.entrySet()) {
            int elapse = entry.getValue();
            
            if(elapse <= fees[0]) {
                costMap.put(entry.getKey(), costMap.getOrDefault(entry.getKey(), 0) + fees[1]);
            } else {
                int cost = fees[1] + (int)Math.ceil((elapse - fees[0]) / (double)fees[2]) * fees[3];
                costMap.put(entry.getKey(), costMap.getOrDefault(entry.getKey(), 0) + cost);
            }
        }
        
        // 차량번호 오름차순 요금 정렬
        List<String> sortedNum = new ArrayList<>(costMap.keySet());
        Collections.sort(sortedNum);
        
        for(String str: sortedNum) {
            costArr.add(costMap.get(str));
        }
        
        answer = costArr.stream().mapToInt(i -> i).toArray();
        
        return answer;
    }
    
    public static void mapping(String time, String num, String op) {        
        String[] timeArr = time.split(":");
        if(op.equals("IN")) {
            map.put(num, new int[2]);
            map.get(num)[0] = Integer.parseInt(timeArr[0]) * 60 + Integer.parseInt(timeArr[1]);
        } else if(op.equals("OUT")) {
            map.get(num)[1] = Integer.parseInt(timeArr[0]) * 60 + Integer.parseInt(timeArr[1]);
        }
    }
}