class Solution {
public:
     int memoization(string& s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += solve(mem, s, i, j);
            }
        }
        return count;
    }
    
    int solve(vector<vector<int>>& mem, string& s, int i, int j) {
        if (i == j) return 1;
        while(i<j)
        {
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    int countSubstrings(string &s) {
  return memoization(s);
    }
};