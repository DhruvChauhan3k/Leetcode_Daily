class Solution {
public:
int check(int i,int amount,vector<int>& coins,vector<vector<int>>&dp)
{
    if(amount==0)return 0;
    if(i==coins.size() or amount<0)return 1e9;
    if(dp[i][amount]!=-1)return dp[i][amount];
    int a=1+check(i,amount-coins[i],coins,dp);
    int b=check(i+1,amount,coins,dp);
    return dp[i][amount]= min(a,b);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int x=check(0,amount,coins,dp);
        if(x==1e9)return -1;
        return x;
    }
};