class Solution {
public:
    int check(vector<int>&prices,int fee,int i,int buy,vector<vector<int>>&dp)
    {
        if(i==prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int a=0,b=0;
        if(buy)
        {
           a=max(check(prices,fee,i+1,0,dp)-(prices[i]+fee),check(prices,fee,i+1,1,dp));
        }
        else
        {
            b=max(check(prices,fee,i+1,1,dp)+prices[i],check(prices,fee,i+1,0,dp));
        }
        return dp[i][buy]= max(a,b);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return check(prices,fee,0,1,dp);
    }
};