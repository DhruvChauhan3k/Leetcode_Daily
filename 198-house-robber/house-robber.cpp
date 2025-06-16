class Solution {
public:
    int tell(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i]=max(nums[i]+tell(i+2,nums,dp),tell(i+1,nums,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return tell(0,nums,dp);
    }
};