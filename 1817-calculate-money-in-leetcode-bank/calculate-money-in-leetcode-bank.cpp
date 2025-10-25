class Solution {
public:
    int totalMoney(int n) {
        int rem=n%7;
        int ni=n/7;
        int ans=0,now=28;
        while(ni){
            ans+=now;
            ni--;
            now+=7;
        }
        ni=1+n/7;
        while(rem){
           rem--;
           ans+=(ni);
           ni++;
        }

        return ans;

    }
};