class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m1,m2;
        int cnt1=0,cnt2=0;
        for(auto it:t)
        {
            if(m2[it]>0)
            {
                m2[it]++;
            }
            else
            {
                m2[it]=1;
                cnt2++;
            }
        }
        int len=INT_MAX;
        int fst=0,cst=0;
        for(int i=0;i<s.size();i++)
        {
           char it=s[i];
           m1[it]++;
            if(m2[it]==m1[it])
            {
                cnt1++;
            }
            if(cnt1==cnt2)
            {
            while(cnt1==cnt2)
            {
                if(len>i-cst+1)
                {
                    fst=cst;
                    len=i-cst+1;
                }
                m1[s[cst]]--;
                if(m1[s[cst]]<m2[s[cst]])
                {
                    cnt1--;
                }
                cst++;
            }
            }
        }
        if(len==INT_MAX)return "";
        return s.substr(fst,len);
    }
};