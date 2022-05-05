function solution(s) {
    let answer = '';
    let temp = s.split(' ');
    console.log(temp);
    for(let i = 0; i < temp.length; i++){
        if(temp[i].length > 0){
            if(temp[i][0] >= 'a' && temp[i][0] <= 'z' || temp[i][0] >= 'A' && temp[i][0] <= 'Z' ){
                answer += temp[i][0].toUpperCase();
                answer += temp[i].slice(1).toLowerCase()+' ';
            }else{
                answer += temp[i][0];
                answer += temp[i].slice(1).toLowerCase()+' ';
            }
        }else{
            answer+=' ';
        }
    }
    
    answer = answer.substr(0, answer.length-1);
    
    return answer;
}
