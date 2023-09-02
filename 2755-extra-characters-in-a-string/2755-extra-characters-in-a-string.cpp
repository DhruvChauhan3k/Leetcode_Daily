class Solution {
public:
    int check(int i,int prev,string &s,unordered_map<string,int>&m, vector<vector<int>>&dp)
    {
        if(i==s.size())
        {
            string temp=s.substr(prev);
            if(m.find(temp)!=m.end())return 0;
            return (i-prev);
        }
        if(dp[i][prev]!=-1)return dp[i][prev];
        int a=1e9,b=1e9,c=1e9;
        int len=(i-prev)+1;
        string temp=s.substr(prev,len);
        if(m.find(temp)!=m.end())
        {
           a=check(i+1,i+1,s,m,dp);
        }
        b=len+check(i+1,i+1,s,m,dp);
        c=check(i+1,prev,s,m,dp);
        return dp[i][prev]= min(a,min(b,c));
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        unordered_map<string,int>m;
        for(auto it:dictionary)m[it]++;
        return check(0,0,s,m,dp);
    }
};