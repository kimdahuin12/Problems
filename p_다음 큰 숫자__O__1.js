function binaryInOneCnt(num){
    let cnt = 0;
    while(Math.floor(num/2) !== 0){
        if(Math.floor(num%2)===1){ cnt++; }
        num = Math.floor(num/2);
    }
    return cnt;
}

function solution(n) {
    let answer = 0;
    
    for(let i = n+1; ; i++){
        let nOneCnt = binaryInOneCnt(n);
        let iOneCnt = binaryInOneCnt(i);
        if(nOneCnt===iOneCnt){ answer = i; break; }
    }
    
    return answer;
}
