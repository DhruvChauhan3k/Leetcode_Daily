class Solution {
public:
    bool check(int i,string s,unordered_map<string,int>&m,vector<int>&dp)
    {
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i];
        string temp;
        for(int j=i;j<s.size();j++){
          temp+=s[j];
          if(m.find(temp)!=m.end()){
            if(check(j+1,s,m,dp)){
                return dp[i]=true;
            }
          }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& w) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_map<string,int>m;
        for(auto it:w)m[it]++;
        return check(0,s,m,dp);
    }
};