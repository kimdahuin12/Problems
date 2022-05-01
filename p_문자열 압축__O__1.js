function solution(s) {
    let str = "", cnt = 0, pos = 0;
    let answer = s.length;     //처음에는 문자열의 길이를 최솟값으로 정한다.
    let tmpNum = 0;
    for(let parsing = 1; parsing <= Math.floor(s.length/2); parsing++){
                            console.log(str);
        pos = 0; str = ""; cnt = 0; tmpNum = 0;
        for(; pos < s.length; pos+=parsing){ //연속으로 몇 개 있는지 센다.
            if(str !== s.substr(pos, parsing)){
                if(str!==""){ //""이면 그냥 처음 부분이므로 개수를 세지 않는다.
                    if(cnt <= 1){ tmpNum += parsing;}
                    else if(cnt > 1) { tmpNum += parsing + cnt.toString().length;}
                }
                str = s.substr(pos,parsing);
                cnt = 1;
            }else{
                cnt++;
            }
        }
        
        //마지막을 위한 부분이다.
        if(str.length >= parsing){
            if(cnt <= 1){ tmpNum += parsing; }
            else if(cnt > 1) { tmpNum += parsing + cnt.toString().length;}
        }else{
            if(cnt <= 1){ tmpNum += str.length; }
            else if(cnt > 1) { tmpNum += str.length + cnt.toString().length; }
        }
        if(tmpNum < answer){ answer = tmpNum; }
    }
    
    return answer;
}
