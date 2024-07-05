function solution(n, results) {
    var answer = 0;
    
    let graph = Array.from(Array(n+1), () => Array(n+1).fill(0))
    results.forEach(([a, b]) => {
        graph[a][b] = 1
        graph[b][a] = -1
    })
        
    for(let k = 1; k <= n; k++) {
        for(let i = 1; i <= n; i++) {
            for(let j = 1; j <= n; j++) {
                if(i === j) continue
                if(graph[i][j] !== 0) continue // 
                
                // if(graph[i][k] + graph[k][j] !== 0) { // ik가 1이고 kj가 0인 경우 문제가 발생하는 코드
                //     graph[i][j] = Math.floor((graph[i][k] + graph[k][j]) / 2);
                // }
                if(graph[i][k] === 1 && graph[k][j] === 1) {
                    graph[i][j] = 1
                    graph[j][i] = -1
                } else if(graph[i][k] === -1 && graph[k][j] === -1) {
                    graph[i][j] = -1
                    graph[j][i] = 1
                }
            }
        }
    }
        
    graph.forEach((gra) => {
        let cnt = 0
        gra.forEach((g) => {
            if(g !== 0) cnt++
        })
        if(cnt === n-1) answer++
    })
    
    return answer;
}