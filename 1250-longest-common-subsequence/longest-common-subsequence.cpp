class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=text2.size();i++){
          dp[n][i]=0;
        }
        for(int j=0;j<=text1.size();j++){
          dp[j][m]=0;
        }

        int ans=0;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--)
            {
                if(dp[i][j]!=-1)continue;
                if(text1[i]==text2[j]){
                    dp[i][j]= 1+dp[i+1][j+1];
                    ans=max(ans,dp[i][j]);
                    continue;
                }
                dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
                ans=max(dp[i][j],ans);
            }
        }

        return dp[0][0];
    }
};