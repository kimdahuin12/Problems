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
    
    //n보다 큼, n을 2진수로 변환했을 때와 1의 개수가 같다.
    //위의 수들중에서 가장 작은 수.
    let nOneCnt = binaryInOneCnt(n);
    //n보다 크다.
    for(let i = n+1; ; i++){
        if(nOneCnt===binaryInOneCnt(i)){
            answer = i; break;
        }
    }
    
    return answer;
}
