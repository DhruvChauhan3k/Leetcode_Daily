class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s=0;
        unordered_map<char,int>m,v;
        for(auto it:s1)m[it]++;
        int n=s2.size(),m1=s1.size();
        int e=0;
        while(e<n)
        {
            v[s2[e]]++;
            while(m.find(s2[e])!=m.end() and v[s2[e]]>m[s2[e]])
            {
                v[s2[s]]--;
                s++;
            }
            if(m.find(s2[e])==m.end())
            {
                while(s<=e)
                {
                    v[s2[s]]--;
                    s++;
                }
            }
            if((e-s)+1==m1)return true;
            e++;
        }
        return false;
    }
};