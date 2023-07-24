class Solution {
public:
   int get(int m,int n,vector<vector<int>>&dp)
   {
   if(n==0 and m==0)return 1;
   if(n<0 or m<0) return 0;
   if(dp[m][n]!=-1)return dp[m][n];
   return dp[m][n]=get(m-1,n,dp)+get(m,n-1,dp);
   }
    int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return get(m-1,n-1,dp);
    }
};