class Solution {
public:
int check(int &n,vector<int>&nums,int i, vector<int>&dp)
{
    if(i>=n)return 1e9;
    if(i==n-1)return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i]=1e9;
    for(int j=1;j<=nums[i];j++)
    {
       dp[i]=min(dp[i],1+check(n,nums,i+j,dp));
    }
    return dp[i];
    
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return check(n,nums,0,dp);
    }
};