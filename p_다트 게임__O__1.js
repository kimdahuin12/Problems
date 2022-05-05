function solution(dartResult) {
    let answer = 0;
    let scores = new Array();
    for(let i = 0; i < dartResult.length; i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            let num = dartResult[i];
            let j = i+1
            while(!isNaN(dartResult[j])){
                num+=dartResult[j];
                j++;
            }
            i = j;
            scores.push(Number(num));
            
        }
        switch(dartResult[i]){
            case 'D': 
                scores[scores.length-1] = Math.pow(scores[scores.length-1], 2);
                break;
            case 'T': 
                scores[scores.length-1] = Math.pow(scores[scores.length-1], 3);
                break;
            case '*': 
                if(scores.length >= 2){
                    scores[scores.length-2]*=2; scores[scores.length-1]*=2;
                }else{
                    scores[scores.length-1]*=2;
                }
                break;
            case '#': 
                scores[scores.length-1]*=-1;
                break;
        }
    }
    
    for(let s of scores){ answer+=s; }
    
    return answer;
}
