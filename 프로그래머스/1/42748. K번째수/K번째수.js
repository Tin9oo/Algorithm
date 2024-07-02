function solution(array, commands) {
    var answer = [];
    
    commands.forEach((e) => {
        // console.log("e["+e[0]+", "+e[1]+", "+e[2]+"]")
        const arr = array.slice(e[0]-1, e[1]).sort((a, b) => a - b)
        // console.log(arr)
        answer.push(arr[e[2]-1])
    })
    return answer;
}