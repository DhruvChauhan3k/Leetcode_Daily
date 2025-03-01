class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+3,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
        int l=nums[i]+dp[i+2];
        int r=dp[i+1];
        dp[i]=max(l,r);
        }

        return dp[0];
    }
};