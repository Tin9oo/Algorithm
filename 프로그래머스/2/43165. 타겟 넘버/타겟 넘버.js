function solution(numbers, target) {
    var answer = 0;
        
    const dfs = (lev = 0, num = 0) => {
        if(lev >= numbers.length) {
            if(num == target) {
                answer++
            }
            return
        }
        
        dfs(lev+1, num + numbers[lev])
        dfs(lev+1, num - numbers[lev])
    }
    
    dfs()
    
    return answer;
}