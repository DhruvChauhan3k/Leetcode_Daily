class Solution {
public:
    int tell(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        int mini=INT_MIN;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        for(int z=i;z<=j;z++)
        {
            int x=nums[z]*nums[i-1]*nums[j+1]+tell(i,z-1,nums,dp)+tell(z+1,j,nums,dp);
            mini=max(x,mini);    
        }
        return dp[i][j]= mini;
    }
    int maxCoins(vector<int>& nums) {
       int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return tell(1,n,nums,dp);
    }
};