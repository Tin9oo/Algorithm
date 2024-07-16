class Solution {    
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        
        int cnt = 0;
        
        while(sb1.length() < t * m) {
            sb1.append(Integer.toString(cnt++, n).toUpperCase());
        }
        
        for(int i = 0; i < t; i++) {
            sb2.append(sb1.charAt(p-1 + i * m));
        }
        
        return sb2.toString();
    }
}