class Solution {
public:
   int check(int i,int k,int buy,vector<int>&prices,vector<vector<vector<int>>>&dp)
   {
       if(i==prices.size() or k==0)return 0;
       if(dp[i][k][buy]!=-1)return dp[i][k][buy];
       int a=0,b=0;
       if(buy)
       {
           a=max(check(i+1,k,0,prices,dp)-prices[i],check(i+1,k,1,prices,dp));
       }
       else
       {
           b=max(check(i+1,k-1,1,prices,dp)+prices[i],check(i+1,k,0,prices,dp));
       }
       return dp[i][k][buy]=max(a,b);
   }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return check(0,k,1,prices,dp);
    }
};