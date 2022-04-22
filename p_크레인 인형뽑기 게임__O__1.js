function solution(board, moves) {
    var answer = 0;
    var basket = [];
    var tmpBoard = new Array(board.length);
    
    for(i = 0; i < board.length; i++){
        tmpBoard[i] = [];
        for(j = board.length-1; j >= 0; j--){
            if(board[j][i]!==0){ tmpBoard[i].push(board[j][i]); }
        }
    }
    
    for(i = 0; i < moves.length; i++){
       var doll = tmpBoard[moves[i]-1].pop();
        if(doll !== undefined){
            if(basket.length===0||basket[basket.length-1]!==doll){ basket.push(doll); }
	    else{ basket.pop(); answer+=2; }
        }
    }
    
    return answer;
}
