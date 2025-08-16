class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int maxi=0;
        int last=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end() and m[s[i]]>=last)
            {
                 last=m[s[i]]+1;
            }
            m[s[i]]=i;
            maxi=max(maxi,i-last+1);
        }
        return maxi;
    }
};