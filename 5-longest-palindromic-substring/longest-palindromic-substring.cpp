class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
        int curr=0,maxi=0;
        pair<int,int>ans;
        for(int i = 0; i < s.size();i++)
        {
            for(int j = i; j < s.size();j++) 
            {
                if(solve(mem, s, i, j))
                {
                    curr=j-i+1;
                    if(curr>maxi)
                    {
                        maxi=curr;
                        ans={i,j};
                    }
                }
            }
        }
        string ret;
        int i=ans.first;
        int j=ans.second;
        for(int k=i;k<=j;k++)
        {
            ret+=s[k];
        }
        return ret;
    }
    int solve(vector<vector<int>>& mem, string& s, int i, int j) {
        if (i >= j) return 1;
        if (mem[i][j]!=-1) return mem[i][j];
        return mem[i][j] = s[i] == s[j] ? solve(mem, s, i+1, j-1) : 0;
    }
};