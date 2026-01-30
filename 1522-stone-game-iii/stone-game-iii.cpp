class Solution {
public:
    int check(int i,vector<int>&s,vector<int>&dp){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int a=-1e9,b=-1e9,c=-1e9;
        a=s[i]-check(i+1,s,dp);
        if(i+1<s.size())b=s[i]+s[i+1]-check(i+2,s,dp);
        if(i+2<s.size())c=s[i]+s[i+1]+s[i+2]-check(i+3,s,dp);
        return dp[i]=max(a,max(b,c));
    }
    string stoneGameIII(vector<int>& s) {
        // vector<vector<int>>dp(s.size(),vector<int>(2,-1));
        vector<int>dp(s.size(),-1);
        int ans=check(0,s,dp);
        if(ans==0)return "Tie";
        return ans<0?"Bob":"Alice";
    }
};