function solution(numbers, hand) {
    var answer = '';
    var rightPos = [2, 3];
    var leftPos = [0, 3];
    for(i = 0; i < numbers.length; i++){
        var nextPos;
        if(numbers[i] == '0') { numbers[i] = '11'; nextPos = [1, 3]; }
        else { nextPos = [(Number(numbers[i])-1)%3, Math.floor((Number(numbers[i])-1)/3)]; }

        if(Number(numbers[i])%3==1){
            answer+='L'; 
            leftPos = nextPos;
        }else if(Number(numbers[i])%3==0){
            answer+='R';
            rightPos = nextPos;
        }else{
            let rightDif = Math.abs(nextPos[0]-rightPos[0])+Math.abs(nextPos[1]-rightPos[1]);
            let leftDif = Math.abs(nextPos[0]-leftPos[0])+Math.abs(nextPos[1]-leftPos[1]);
            
            if(rightDif > leftDif){
                //왼손이 더 가까움
                answer+='L';
                leftPos = nextPos;
            }else if(rightDif < leftDif){
                //오른손이 더 가까움
                answer+='R';
                rightPos = nextPos;
            }else{
                //둘이 같음
                if(hand==='left'){ answer+='L'; leftPos = nextPos; }
                else{ answer+='R'; rightPos = nextPos; }
            }
        }
    }
    
    return answer;
}
