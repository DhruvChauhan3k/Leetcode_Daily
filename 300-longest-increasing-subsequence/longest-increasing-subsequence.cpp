class Solution {
public:
    int tell(int i,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i<0)
        {
            return 0;
        }
        if(dp[i][prev]!=-1)
        {
            return dp[i][prev];
        }
        int x=0;
        if(prev==nums.size() or nums[i]<nums[prev])
        {
            x=1+tell(i-1,i,nums,dp);
        }
        return dp[i][prev]= max(tell(i-1,prev,nums,dp),x);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return tell(n-1,n,nums,dp);
    }
};