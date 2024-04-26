class Solution {
    static int cnt = 0;
    
    public int solution(int[] numbers, int target) {
        int answer = 0;
        
        dfs(numbers, target, 1, numbers[0]);
        dfs(numbers, target, 1, -1 * numbers[0]);

        answer = cnt;
        
        return answer;
    }
    
    public static void dfs(int[] numbers, int target, int level, int sum) {
        if(level == numbers.length) {
            if(sum == target) {
                cnt++;
            }
            return;
        }
        
        dfs(numbers, target, level + 1, sum + numbers[level]);
        dfs(numbers, target, level + 1, sum - numbers[level]);
    }
}