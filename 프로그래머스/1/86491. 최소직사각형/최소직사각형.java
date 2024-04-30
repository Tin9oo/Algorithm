import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        
        int w = 0;
        int h = 0;
        
        // boolean flag = true;
        
        for(int i = 0; i < sizes.length; i++) {
            Arrays.sort(sizes[i]);
        }
        
        // for(int i = 1; i <= 1000; i++) {
        //     for(int j = 1; j <= 1000; j++) {
        //         // System.out.println("i = " + i + ", j = " + j);
        //         for(int[] size: sizes) {
        //             if(!(size[0]<=i&&size[1]<=j || size[1]<=i&&size[0]<=j)) {
        //                 // System.out.println("Break !!");
        //                 flag = false;
        //                 break;
        //             }
        //         }
        //         if(flag) {
        //             System.out.println("Answer : " + i*j);
        //             return i*j;
        //         }
        //     }
        // }
        
        for(int i = 0; i < sizes.length; i++) {
            if(w < sizes[i][0]) {
                w = sizes[i][0];
            }
            if(h < sizes[i][1]) {
                h = sizes[i][1];
            }
        }
        
        return w*h;
    }
}