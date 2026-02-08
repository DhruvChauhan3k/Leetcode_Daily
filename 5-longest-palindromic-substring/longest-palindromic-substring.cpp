class Solution {
public:
string memoization(string& s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
        int len = 0;
        int si=0,sj=0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                if(mem[i][j]==-1)solve(mem,s,i,j);
                if(mem[i][j]==1 and (j-i)+1>len){
                    len=j-i+1;
                    si=i;
                    sj=j;
                };
            }
        }
        string sans;
        for(int i=si;i<=sj;i++)sans+=s[i];
        return sans;
    }
    
    int solve(vector<vector<int>>& mem, string& s, int i, int j) {
        if (i >= j) return 1;
        if(s[i]!=s[j])return 0;
        if(mem[i][j]!=-1)return mem[i][j];
        mem[i][j]=solve(mem,s,i+1,j-1);
        return mem[i][j];
    }
    string longestPalindrome(string s) {
        return memoization(s);
    }
};