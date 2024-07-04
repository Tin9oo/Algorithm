function solution(N, number) {
    const SIZE = 9
    
    let dp = Array(SIZE).fill(0).map(e => new Set())
        
    for(let i = 1; i < SIZE; i++) {
        dp[i].add('1'.repeat(i) * N)
        for(let j = 1; j < i; j++) {
            for(const a of dp[j]) {
                for(const b of dp[i-j]) {
                    dp[i].add(a+b)
                    if(a-b !== 0) dp[i].add(a-b)
                    dp[i].add(a*b)
                    dp[i].add(Math.floor(a/b))
                }
            }
        }
        
        if(dp[i].has(number)) return i
    }
    
    return -1;
}