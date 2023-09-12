class Solution {
public:
    int minDeletions(string s) {
        int ans=0;
        unordered_map<char,int>m;
        unordered_map<int,int>n;
        string s1;
        for(auto it:s)
        {
            m[it]++;
            if(m[it]==1)s1+=it;
        }
        for(auto it:s1)
        {
            if(n.find(m[it])==n.end())
            {
                n[m[it]]++;
            }
            else
            {
                while(n.find(m[it])!=n.end() and m[it]!=0)
                {
                    ans++;
                    m[it]--;
                }
                n[m[it]]++;
            }
        }
        return ans;
    }
};