class Solution {
public:
    int check(int i,int num,vector<int>&tar,vector<vector<int>>&dp)
    {
        if(num==0)return 0;
        if(i>=tar.size() or num<0)return 1e9;
        if(dp[i][num]!=-1)return dp[i][num];
        return dp[i][num]= min(1+check(i,num-tar[i],tar,dp),check(i+1,num,tar,dp));
    }
    int minimumNumbers(int num, int k) {
        if(num==0 and k==0)return 0;
        if(k==0)
        {
            if(num%10==0)return 1;
            return -1;
        }
        vector<int>tar;
        for(int i=0;i<=num;i++)
        {
            if(i%10==k)tar.push_back(i);
        }
        vector<vector<int>>dp(tar.size()+1,vector<int>(num+1,-1));
        int ans=check(0,num,tar,dp);
        return ans>=1e9?-1:ans;
    }
};