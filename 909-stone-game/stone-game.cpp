class Solution {
public:
int check(int s,int end,vector<int>&piles,vector<vector<int>>&dp){
    if(s>end)return 0;
    if(dp[s][end]!=-1)return dp[s][end];
    return dp[s][end]=max(piles[s]-check(s+1,end,piles,dp),piles[end]-check(s,end-1,piles,dp));
}
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        return check(0,piles.size()-1,piles,dp)<=0?false:true;
    }
};