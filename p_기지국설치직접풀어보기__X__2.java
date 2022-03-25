class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;

        //모두 전파 닿을때까지
        boolean[] spread = new boolean[n+1];
        int stationCnt = 0;
        for(int i = 1; i <= n; i++){
            if(stationCnt < stations.length){
                if(i >= stations[stationCnt]-w &&i <= stations[stationCnt]+w){
                    spread[i] = true;
                }
                if(stations[stationCnt]+w == i){
                    stationCnt++;
                }
            }
            if(!spread[i]){
               answer++;
               for(int j = i; j <= i+w*2; j++){
                    if(j >= n+1){i = j; break; }
                    if(spread[j]){i = j; break;}
                   spread[j] = true;
                }
            }
        }
        
        return answer;
    }
}
