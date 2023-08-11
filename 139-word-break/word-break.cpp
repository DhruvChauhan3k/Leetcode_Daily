class Solution {
public:
bool check(int i,string &s, unordered_map<string,int>&m,string curr, vector<unordered_map<string,bool>>&dp)
{
    curr+=s[i];
    if(dp[i].find(curr)!=dp[i].end())return dp[i][curr];
    if(i==s.size()-1)
    {
        if(m.find(curr)!=m.end())return true;
        return false;
    }
    bool a=false;
    if(m.find(curr)!=m.end())
    {
        a=check(i+1,s,m,"",dp);
    }
    bool b=check(i+1,s,m,curr,dp);
    return dp[i][curr]= a or b;
}
    bool wordBreak(string s, vector<string>& w) {
        unordered_map<string,int>m;
        vector<unordered_map<string,bool>>dp(s.size());
        for(auto it:w)m[it]++;
        string curr;
        return check(0,s,m,curr,dp);
    }
};