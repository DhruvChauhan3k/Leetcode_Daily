class Solution {
public:
    int get(vector<int>& deno, int n, int value,vector<vector<int>>&dp)
{
    if(value==0)return 1;
    if(n<0 or value<0)return 0;
    if(dp[n][value]!=-1)return dp[n][value];
    return dp[n][value]=get(deno,n-1,value,dp)+get(deno,n,value-deno[n],dp);
}
    int change(int value, vector<int>& deno) {
        int n=deno.size();
        vector<vector<int>>dp(n,vector<int>(value+1,-1));
        return get(deno,n-1,value,dp);
    }
};