function solution(board)
{
    let answer = 0;
    //1이 나오면 오른, 아래, 대각선을 검사한다.
    for(let i = 0; i < board.length; i++){
        for(let j = 0; j < board[i].length; j++){
            if(board[i][j]===1){
                let len = 1;
                while(i + len < board.length && j + len < board[i].length){
                    let chk = true;
                    for(let a = j; a < j + len; a++){
                        if(board[i+len][a]!==1){ chk = false;}
                    }
                    for(let a = i; a < i + len; a++){
                        if(board[a][j+len]!==1){ chk = false;}
                    }
                    if(board[i+len][j+len]!==1){ chk = false; }
                    if(chk){ len++; }
                    else{break;}
                }
                if(len*len > answer){ answer = len*len; }
            }
        }
    }

    return answer;
}
