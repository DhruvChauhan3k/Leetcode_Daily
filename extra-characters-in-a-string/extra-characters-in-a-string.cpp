class Solution {
public:
    int check(int i,string s,unordered_map<string,int>&m,vector<int>&dp)
    {
        if(i==s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int a=1+check(i+1,s,m,dp);
        int b=INT_MAX;
        string tmp;
        for(int j=i;j<s.size();j++)
        {
            tmp+=s[j];
            if(m.find(tmp)!=m.end())
            {
                b=min(b,check(j+1,s,m,dp));
            }
        }
        return dp[i]= min(a,b);
    }
    int minExtraChar(string s, vector<string>& dic) {
        vector<int>dp(s.size()+1,-1);
        unordered_map<string,int>m;
        for(auto it:dic)
        {
            m[it]++;
        }
        return check(0,s,m,dp);
    }
};