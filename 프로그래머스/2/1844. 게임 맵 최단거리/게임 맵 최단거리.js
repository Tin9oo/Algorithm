function solution(maps) {
    var answer = -1;
    
    const dr = [-1, 0, 1, 0]
    const dc = [0, 1, 0, -1]
    
    const bfs = () => {
        let q = []
        let vis = new Array(maps.length).fill(0).map(() => new Array(maps[0].length).fill(0))
        
        vis[0][0] = 1
        q.push([0, 0, 1])
        
        while(q.length !== 0) {
            const [r, c, d] = q.shift()
            
            if(r === maps.length-1 && c === maps[0].length-1) {
                answer = d
                return
            }
            
            for(let i = 0; i < dr.length; i++) {
                const nr = r+dr[i]
                const nc = c+dc[i]
                
                if(nr<0||nc<0||maps.length<=nr||maps[0].length<=nc) continue
                if(vis[nr][nc] === 1) continue
                if(maps[nr][nc] == 0) continue
                
                vis[nr][nc] = 1
                q.push([nr, nc, d+1])
            }
        }
    }
    
    bfs()
    
    return answer;
}