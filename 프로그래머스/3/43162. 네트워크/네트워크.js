function solution(n, computers) {
    var answer = 0;
    
    let vis = []
    
    const bfs = (idx, vis) => {
        if(vis.includes(idx)) return
        
        // console.log("bfs(", idx, ")")
        
        let q = []
        vis.push(idx)
        q.push(idx)
        
        answer++

        while(q.length !== 0) {
            let ci = q.shift()
            // console.log('cur ci=', ci)

            for(let i = 0; i < n; i++) {
                if(vis.includes(i)) continue
                if(computers[ci][i] !== 1) continue
                if(ci === i) continue

                vis.push(i)
                q.push(i)
            }
        }
    }

    for(let i = 0; i < n; i++) {
        bfs(i, vis)        
    }
    
    return answer;
}