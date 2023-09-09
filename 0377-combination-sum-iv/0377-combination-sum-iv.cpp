class Solution {
public:
    int check(int t,vector<int>&nums,vector<int>&dp)
    {
        if(t==0)return 1;
        if(t<0)return 0;
        if(dp[t]!=-1)return dp[t];
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=check(t-nums[i],nums,dp);
        }
        return dp[t]= ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return check(target,nums,dp);
    }
};