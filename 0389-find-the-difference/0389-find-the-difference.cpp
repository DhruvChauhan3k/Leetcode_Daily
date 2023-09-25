class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<char,int>m1;
        for(auto it:s)
        {
            m1[it]++;
        }
        for(auto it:t)
        {
            if(m1[it]==0)return it;
            m1[it]--;
        }
        return 'dhruv';
    }
};