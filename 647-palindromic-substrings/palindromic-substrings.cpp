class Solution {
public:
     int memoization(string& s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                if(mem[i][j]==-1)mem[i][j]=solve(mem,s,i,j);
                count+=mem[i][j];
            }
        }
        return count;
    }
    
    int solve(vector<vector<int>>& mem, string& s, int i, int j) {
        if (i >= j) return 1;
        if(s[i]!=s[j])return 0;
        if(mem[i][j]!=-1)return mem[i][j];
        mem[i][j]=solve(mem,s,i+1,j-1);
        return mem[i][j];
    }
    int countSubstrings(string &s) {
  return memoization(s);
    }
};