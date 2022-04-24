function solution(numbers) {
    var answer = '';
    var tempNumbers = numbers.slice();
    for(let i = 0; i < tempNumbers.length-1; i++){
        for(let j = i+1; j < tempNumbers.length; j++){
            if(tempNumbers[i]+'' < tempNumbers[j]+''){
                let temp = tempNumbers[j];
                tempNumbers[j] = tempNumbers[i];
                tempNumbers[i] = temp; 
            }
        }
    }
    
    for(let tN of tempNumbers){
        answer+=tN;
    }

    return answer;
}
