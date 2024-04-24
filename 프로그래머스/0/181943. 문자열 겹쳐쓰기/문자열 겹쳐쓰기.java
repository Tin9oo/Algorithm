class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        String answer = "";
        
        StringBuilder sb = new StringBuilder(my_string);
        
        for(int i = 0; i < my_string.length(); i++) {
            if(i >= s && i < s + overwrite_string.length())
                sb.setCharAt(i, overwrite_string.charAt(i-s));
        }
        
        answer = sb.toString();
        
        return answer;
    }
}