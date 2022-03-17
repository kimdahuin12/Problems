class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;

        //모두 전파 닿을때까지
        boolean[] spread = new boolean[n+1];

        for(int i = 0; i < stations.length; i++){
            for(int j = stations[i]-w; j <= stations[i]+w; j++){
                    if(j >= n+1 || j < 0)continue;
                    if(spread[j])continue;
                   spread[j] = true;
            } 
        }

        for(int i = 1; i <= n; i++){
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
