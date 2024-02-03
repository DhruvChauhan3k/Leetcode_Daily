class Solution {
public:
    int check(vector<int>& arr, int k,int i,vector<int>&dp)
    {     
        int n=arr.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0,maxi=0;
        for(int j=i;j<min(i+k,n);j++)
        {
            maxi=max(maxi,arr[j]);
            ans=max(ans,maxi*(j+1-i)+check(arr,k,j+1,dp));
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return check(arr,k,0,dp);
    }
};