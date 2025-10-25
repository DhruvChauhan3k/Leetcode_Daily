class Solution {
    public int totalMoney(int n) {
         int ni=n/7;
        int ans=0,now=28;
        while(ni>0){
            ans+=now;
            ni--;
            now+=7;
        }
        ni=1+n/7;
        now=n%7;
        while(now>0){
           now--;
           ans+=(ni);
           ni++;
        }

        return ans;

    }
}