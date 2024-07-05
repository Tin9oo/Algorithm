function solution(n, edge) {
    var answer = 0;
    
    // Init variable
    // 연결 여부를 2차원 배열로 저장하면 메모리 초과
    let q = []
    let vis = Array(n+1).fill(0)
    let maxCnt = 0
    
    // let adjList = Array(n+1).fill().map(() => new Set())
    let adjList = Array(n+1).fill().map(() => [])
    // let adjList = Array.from(Array(n+1), () => [])
    edge.forEach(([u, v]) => {
        adjList[u].push(v)
        adjList[v].push(u)
    })
    console.log(adjList)
    
    // bfs
    vis[1] = 1
    q.push([1, 0])
    
    while(q.length !== 0) {
        const [node, cur_count] = q.shift()
        
        if(maxCnt < cur_count) {
            maxCnt = cur_count
            answer = 1
        } else if(maxCnt === cur_count) {
            answer++
        }
        
        adjList[node].forEach((nextNode) => {
            if(vis[nextNode] === 1) return

            // console.log("node=", nextNode)
            // console.log("vis=", vis)
            
            vis[nextNode] = 1
            q.push([nextNode, cur_count+1])  
        })
    }
    
    return answer;
}