function solution(progresses, speeds) {
    let answer = [];
    while(progresses.length > 0){
        for(let i = 0; i < progresses.length; i++){
            if(progresses[i]<100){ progresses[i]+=speeds[i]; }
        }
        let cnt = 0;
        for(let i = 0; i < progresses.length; i++){
            if(progresses[i]>=100){ cnt++; }
            else{ break; }
        }
        if(cnt > 0){
            answer.push(cnt);
            progresses.splice(0, cnt);
            speeds.splice(0, cnt);
        }
    }
    
    return answer;
}
