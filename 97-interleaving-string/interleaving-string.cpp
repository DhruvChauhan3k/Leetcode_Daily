class Solution {
public:
    bool check(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<vector<int>>>&v){
        if(i==s1.size() and j==s2.size() and k==s3.size())return true;
        if(k==s3.size())return false;
        if(v[i][j][k]!=-1)return v[i][j][k];
        bool a=false,b=false;
        if(i<s1.size() and s1[i]==s3[k]){
           a=check(i+1,j,k+1,s1,s2,s3,v);
        }
        if(j<s2.size() and s2[j]==s3[k]){
            b=check(i,j+1,k+1,s1,s2,s3,v);
        }
        return v[i][j][k]= a || b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>v(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return check(0,0,0,s1,s2,s3,v);
    }
};