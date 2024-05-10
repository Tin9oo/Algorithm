import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = {};
        
        ArrayList<Integer> al = new ArrayList<>();
        
        for(int[] com: commands) {
            int[] tmpArr = new int[com[1]-com[0]+1];
            System.arraycopy(array, com[0]-1, tmpArr, 0, com[1]-com[0]+1);
            // tmpArr = Arrays.copyOfRange(array, com[0]-1, com[1]);
            Arrays.sort(tmpArr);
            al.add(tmpArr[com[2]-1]);
        }
        
        answer = al.stream().mapToInt(i->i).toArray();
        
        return answer;
    }
}