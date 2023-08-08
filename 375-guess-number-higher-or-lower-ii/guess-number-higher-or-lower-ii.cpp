class Solution {
public:
    int check(int s,int e,vector<vector<int>>&dp)
    {
        if(s>=e)return 0;
        if(dp[s][e]!=-1)return dp[s][e];
        int ans=1e9;
        for(int i=s;i<=e;i++)
        {
            ans= min(ans,i+max(check(s,i-1,dp),check(i+1,e,dp)));
        }
        return dp[s][e]= ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return check(1,n,dp);
    }
};