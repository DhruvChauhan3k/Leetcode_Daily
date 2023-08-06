class Solution {
public:
bool check(int i1,int i2,int i3,string s1,string s2,string s3,vector<vector<vector<int>>>&dp)
{
    if(i3==s3.size() and i1==s1.size() and i2==s2.size())return true;
    if(dp[i1][i2][i3]!=-1)return dp[i1][i2][i3];
    bool a=false,b=false;
    if(i1<s1.size() and s1[i1]==s3[i3])
    {
        a=check(i1+1,i2,i3+1,s1,s2,s3,dp);
    }
    if(i2<s2.size() and s2[i2]==s3[i3])
    {
        b=check(i1,i2+1,i3+1,s1,s2,s3,dp);
    }
    return dp[i1][i2][i3]= a or b;
}
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()<s2.size())
        {
            swap(s1,s2);
        }
        if(s1.size()+s2.size()!=s3.size())
        {
            return false;
        }
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return check(0,0,0,s1,s2,s3,dp);
    }
};