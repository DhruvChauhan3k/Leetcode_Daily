class Solution {
public:
int check(vector<int>&nums, vector<int>&dp,int t)
{
    if(t<0)return 0;
    if(t==0)
    {
        return 1;
    }
    if(dp[t]!=-1)return dp[t];
    int now=0;
    for(int k=0;k<nums.size();k++)
    {
       now+=check(nums,dp,t-nums[k]);
    }
    return dp[t]=now;
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        int ans=check(nums,dp,target);
        return ans;
    }
};