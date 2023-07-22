class Solution {
public:
    int check(int i,int j,string &t1,string &t2,vector<vector<int>>&dp,int n,int m)
    {
        if(i>=n or j>=m)return 0;
        int x=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i]==t2[j])
        {
            x=1+check(i+1,j+1,t1,t2,dp,n,m);
            return dp[i][j]= x;
        }
        int y=0,z=0;
        y= check(i+1,j,t1,t2,dp,n,m);
        z=check(i,j+1,t1,t2,dp,n,m);
        return dp[i][j]= max(x,max(y,z));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j+1],max(dp[i+1][j],dp[i][j+1]));
                }
                ans=max(dp[i][j],ans);
            }
        }
        return ans;
    }
};