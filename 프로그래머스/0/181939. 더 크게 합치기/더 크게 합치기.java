class Solution {
    public int solution(int a, int b) {
        int answer = 0;
        String i1 = String.valueOf(a);
        String i2 = String.valueOf(b);
        if(Integer.valueOf(i1+i2) > Integer.valueOf(i2+i1)) {
            answer = Integer.valueOf(i1+i2);
        } else {
            answer = Integer.valueOf(i2+i1);
        }
        return answer;
    }
}