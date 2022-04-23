function solution(board, moves) {
    var answer = 0;
    var basket = [];
    
    for(move of moves){
        for(i = 0; i < board.length; i++){
            var doll = board[i][move-1];
            if(doll!==0){
                board[i][move-1] = 0;
                if(basket.length===0||basket[basket.length-1]!==doll){ basket.push(doll); }
                else{ basket.pop(); answer+=2; }
                break;
            }
        }
    }
    
    return answer;
}
