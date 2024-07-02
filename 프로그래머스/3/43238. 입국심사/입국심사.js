function solution(n, times) {
    var answer = 0;
    
    const log = true
    
    times.sort((a, b) => a - b)
    
    let lo = 1
    let hi = n * times[times.length-1]
    let mid
    
    while(lo <= hi) {
        mid = Math.floor((lo+hi)/2)
        // if(log) console.log("mid=", mid)
        
        let cap = times.reduce(function calc(a, b) {
            return a + Math.floor(mid / b)
        }, 0) // 초기값 추가
        // if(log) console.log("cap=", cap)
        
        if(cap >= n) {
            hi = mid-1
            answer = mid
        } else {
            lo = mid+1
        }
    }
    
    return answer;
}