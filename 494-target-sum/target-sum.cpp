class Solution {
public:
    int tell(int i,int t,vector<int>&nums,vector<unordered_map<int,int>>&dp)
    {
        if(i==-1)
        {
            if(t==0)
            {
                return 1;
            }
            return 0;
        }
       
        if(dp[i].find(t)!=dp[i].end())
        {
            return dp[i][t];
        }
        int l=tell(i-1,t-nums[i],nums,dp);
        int r=tell(i-1,t+nums[i],nums,dp);
        return dp[i][t]=l+r;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        return tell(n-1,target,nums,dp);
    }
};