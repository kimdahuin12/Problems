function solution(citations) {
    var answer = 0;
    citations.sort((a, b)=> b-a);
    let flag = false;
    for(let i = 0; i < citations.length; i++){
        for(let j = citations[i]; j >= 0; j--){
            if(i+1 < citations.length && citations[i+1] >= j) break;
            if(i+1 >= j){
                answer = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    console.log(citations);
    return answer;
}
