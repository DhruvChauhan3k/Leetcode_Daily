class Solution {
public:
    long long get(long long n, vector<long long>&dp)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=get(n-1,dp)+get(n-2,dp);
}
    int climbStairs(int n) {
        vector<long long>dp(n+1,-1);
    long long ans=get(n,dp);
    return ans;
    }
};