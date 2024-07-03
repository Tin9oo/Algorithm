function solution(begin, target, words) {
    var answer = 100;
    
    const dfs = (lev = 0, cur_word = begin, vis = []) => {
        if(lev >= words.length) {
            if(cur_word === target) {
                answer = Math.min(answer, lev)
            }
            return
        }
        if(cur_word === target) {
            answer = Math.min(answer, lev)
            return
        }
        
        for(let i = 0; i < words.length; i++) {
            let cnt = 0
            for(let j = 0; j < cur_word.length; j++) {
                if(cur_word[j] !== words[i][j]) cnt++
            }
            if(cnt !== 1) continue
            if(vis.includes(words[i])) continue
            // console.log(cur_word, "->", words[i])
            vis.push(words[i])
            dfs(lev+1, words[i], vis.slice())
        }
    }
    
    dfs()
    
    answer  = answer === 100 ? 0 : answer
    
    return answer;
}