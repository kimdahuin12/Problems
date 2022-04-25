function solution(numbers) {
    var answer = '';
    numbers.sort(function(a, b){
        if(a.toString()+b.toString() < b.toString()+a.toString()){
            return 1;
        }
        if(a.toString()+b.toString() > b.toString()+a.toString()){
            return -1;
        }
        return 0;
    });
    
    for(let n of numbers){
        answer+=n;
    }
    if(answer[0]=='0')answer = '0';

    return answer;
}
