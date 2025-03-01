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
        int l=nums[i]+tell(i+2,nums,dp);
        int r=tell(i+1,nums,dp);
        return dp[i]=max(l,r);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return tell(0,nums,dp);
    }
};