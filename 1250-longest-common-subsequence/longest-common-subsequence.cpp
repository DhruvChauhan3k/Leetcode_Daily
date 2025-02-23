class Solution {
public:
    int check(int i,string &text1,int j,string&text2,vector<vector<int>>&dp){
        if(i==text1.size() or j==text2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]= 1+check(i+1,text1,j+1,text2,dp);
        }
        return dp[i][j]= max(check(i+1,text1,j,text2,dp),check(i,text1,j+1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return check(0,text1,0,text2,dp);
    }
};