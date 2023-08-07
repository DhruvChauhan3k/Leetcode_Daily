class Solution {
public:
    int check(int i,int ck,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(i>=prices.size())return 0;
        if(dp[i][ck]!=-1)return dp[i][ck];
        int a=0,b=0;
        if(ck==0)
        {
            a=-prices[i]+check(i+1,1,prices,dp);
            b=check(i+1,0,prices,dp);
            return dp[i][ck]= max(a,b);
        }
        else
        {
            a=prices[i]+check(i+2,0,prices,dp);
            b=check(i+1,1,prices,dp);
            return dp[i][ck]= max(a,b);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return check(0,0,prices,dp);
    }
};