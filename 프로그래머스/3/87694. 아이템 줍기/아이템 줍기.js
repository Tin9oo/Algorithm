function solution(rectangle, characterX, characterY, itemX, itemY) {
    var answer = 0;
    
    const MAP_SIZE = (50 + 1) * 2
    let map = Array.from(Array(MAP_SIZE), () => Array(MAP_SIZE).fill(0))
    
    const dy = [-1, 0, 1, 0]
    const dx = [0, 1, 0, -1]
    
    rectangle = rectangle.map((rec) => rec.map((e) => e*2)) // 쉬운 생성법이 있나?
    characterX *= 2
    characterY *= 2
    itemX *= 2
    itemY *= 2
    
    // console.log(rectangle)
    
    // 도형이 있는 부분에 값을 ++ 해서 모든 도형에 대해 수행한다.
    // 테두리는 +1, 도형 내부는 +2를 해서 테두리를 인식할 수 있게 한다.
    // 여러 도형이 겹치는 경우 테두리여도 2 이상이 될 수 있는데 기존 값이 1인 경우 증감을 안하여서 값을 유지한다.
    
    // 1, 1
    // 1, 1 인 경우 돌아가야하는데 그냥 빠른 길로 찾아가는 문제가 발생
    // 해상도를 높인다.
    const makeMap = () => {
        rectangle.forEach(rec => {
            let [x1, y1, x2, y2] = rec
            for(let i = y1; i <= y2; i++) {
                for(let j = x1; j <= x2; j++) {
                    if(i===y1||i===y2||j===x1||j===x2) {
                        if(map[i][j] !== 1) map[i][j]++
                    }
                    else map[i][j] += 2
                }
            }
        })
    }
    
    makeMap()
    for(let i = map.length-1; i >= 0; i--) {
        console.log(map[i].join(' '))      
    }
    
    const bfs = () => {
        let q = []
        let vis = Array.from(Array(MAP_SIZE), () => Array(MAP_SIZE).fill(0))
        
        // console.log(characterX, characterY, 0)
        
        vis[characterY][characterX] = 1 // 이거를 push, includes로 비교했었는데 성능이 너무 안좋았다.
        q.push([characterX, characterY, 0])
        
        while(q.length !== 0) {
            const [x, y, c] = q.shift()
            
            if(x===itemX && y===itemY) {
                answer = c
                return
            }
            
            for(let i = 0; i < dx.length; i++) {
                const [nx, ny, nc] = [x+dx[i], y+dy[i], c+1]
                
                if(nx<0||ny<0||MAP_SIZE<=nx||MAP_SIZE<=ny) continue
                if(vis[ny][nx] === 1) continue // nx, ny가 2배가 되면 또 건너뛰는 현상 발생
                if(map[ny][nx] !== 1) continue
                
                // console.log(nx, ny, nc)
                
                vis[ny][nx] = 1
                q.push([nx, ny, nc])
            }
        }
    }
    
    bfs()
    
    return answer/2;
}