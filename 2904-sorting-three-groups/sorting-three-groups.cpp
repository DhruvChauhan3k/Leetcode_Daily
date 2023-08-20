class Solution {
public:
    int check(int i,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==nums.size())return 0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        // int a=0,b=0;
        int k;
        if(prev==0)k=1;
        else k=prev;
        int a=1e9;
        for(;k<=3;k++)
        {
            if(nums[i]==k)
            {
                a=min(a,check(i+1,k,nums,dp));
            }
            else
            {
                a=min(a,1+check(i+1,k,nums,dp));
            }
        }
        return dp[i][prev]= a;
    }
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(4,-1));
        return check(0,0,nums,dp);
    }
};