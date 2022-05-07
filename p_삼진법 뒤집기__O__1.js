function solution(n) {
    let answer = 0;
    let ternary = '';
    
    while(n != 0){
        ternary += n%3;
        n = Math.floor(n/3);
    }
    let baseThree = 1;
    for(let t = ternary.length-1; t >= 0; t--){
        answer+=Number(ternary[t])*baseThree;
        baseThree*=3;
    }
    
    return answer;
}
