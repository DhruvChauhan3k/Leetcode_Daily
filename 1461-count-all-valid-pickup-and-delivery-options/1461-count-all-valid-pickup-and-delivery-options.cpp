class Solution {
public:
    int countOrders(int n) {
        long long int mod=1e9+7;
        vector<long long int>dp(n+1,1);
        for(int i=2;i<=n;i++)
        {

            dp[i]=(dp[i-1]%mod*((((i-1)*2+1)%mod*((i-1)*2+2))/2%mod)%mod)%mod;
        }
        return dp[n];
    }
};