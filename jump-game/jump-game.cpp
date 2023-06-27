class Solution {
public:
    bool check(int &n,vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=n)return false;
        if(i==n-1)return true;
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++)
        {
            if(check(n,nums,i+j,dp))
            {
                dp[i]=true;
                return dp[i];
            }
        }
        dp[i]=false;
        return dp[i];
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return check(n,nums,0,dp);
    }
};