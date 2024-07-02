function solution(citations) {
    var answer = 0;
    
    const log = false
    
    const n = citations.length
    
    citations.sort((a, b) => b - a)
    if(log) console.log(citations)
    
    citations.forEach((e, i) => {
        if(log) {
            console.log("current element: ", e)
            console.log(citations.slice(0, i+1))
            console.log(citations.slice(i+1, n))
        }
        if(e >= i+1 && e >= n-i-1) {
            answer = i+1
        }
    })
    
    return answer;
}