class Solution {
    public int totalMoney(int n) {
        int prevMon=0,last=0;
        int nowInd=1;
        int ans=0;
        while(nowInd<=n){
           if(nowInd%7==1){
             prevMon++;
             last=prevMon;
           }
             ans+=(last);
             last++;
             nowInd++;
        }
        return ans;
    }
}