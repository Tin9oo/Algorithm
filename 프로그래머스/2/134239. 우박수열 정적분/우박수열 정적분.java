import java.util.*;

class Solution {
    public double[] solution(int k, int[][] ranges) {
        double[] answer = {};
        
        List<Integer> arr = ubak(k);
        // System.out.println(arr.toString());
        List<Double> arr2 = ubakSize(arr);
        // System.out.println(arr2.toString());

        int n = arr.size() - 1;
        
        answer = new double[ranges.length];
        for(int i = 0; i < ranges.length; i++) {
            int start = ranges[i][0];
            int end = n + ranges[i][1];
            
            if(start > end) {
                answer[i] = -1;
                continue;
            }
            
            double size = 0;
            for(int j = start; j < end; j++) {
                size += arr2.get(j);
            }
            answer[i] = size;
        }
        
        return answer;
    }
    
    static List<Integer> ubak(int k) {
        List<Integer> arr = new ArrayList<>();
        
        arr.add(k);
        
        while(k>1) {
            if(k%2 == 0) k/=2;
            else {
                k*=3;
                k++;
            }
            arr.add(k);
        }
        
        return arr;
    }
    
    static List<Double> ubakSize(List<Integer> arr) {
        List<Double> sizeArr = new ArrayList<>();
        
        for(int i = 0; i < arr.size() - 1; i++) {
            double size = Math.abs(arr.get(i) - arr.get(i+1)) / 2.0;
            size += Math.min(arr.get(i), arr.get(i+1));
            
            sizeArr.add(size);
        }
        
        return sizeArr;
    }
}