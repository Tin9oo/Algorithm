function solution(numbers) {
    var answer = '';
    
    answer = numbers.sort((a, b) => ('' + b + a) - ('' + a + b)).join('')
    
    if(answer[0] == '0') answer = '0'
    
    return answer;
}