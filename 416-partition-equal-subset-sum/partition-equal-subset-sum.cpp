class Solution {
public:
bool check(int i,int t,vector<int>& nums,vector<vector<int>>&dp)
{
    if(t==0)return true;
    if(t<0 or i==nums.size())return false;
    if(dp[i][t]!=-1)return dp[i][t];
    bool a=check(i+1,t-nums[i],nums,dp);
    bool b=check(i+1,t,nums,dp);
    return dp[i][t]=a or b;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum%2!=0)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        bool ans=check(0,sum/2,nums,dp);
        return ans;
    }
};