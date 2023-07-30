int n,m;
class Solution {
public:
    int check(int i,int j,vector<vector<int>>&o,vector<vector<int>>&dp)
    {
        
        if(i>n-1 or j>m-1 or o[i][j]==1)return 0;
        if(i==n-1 and j==m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=check(i+1,j,o,dp)+check(i,j+1,o,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        n=o.size(),m=o[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return check(0,0,o,dp);
    }
};