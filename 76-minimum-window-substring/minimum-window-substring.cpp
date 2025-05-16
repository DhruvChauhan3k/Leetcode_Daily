class Solution {
public:
    string minWindow(string s, string t) {
        int cnt=0;
        unordered_map<char,int>m,n;
        for(auto it:t)
        {
            if(m.find(it)==m.end())cnt++;
            m[it]++;
        }
        int st=0,e=0,ans=1e9,now=0;
        int fs=0,fe=0;
        string fin;
        while(e<s.size())
        {
            n[s[e]]++;
            if(n[s[e]]==m[s[e]])now++;
            while(cnt==now)
            {
                if(e+1-st<ans)
                {
                    fs=st;
                    fe=e;
                }
                ans=min(ans,(e+1-st));
                n[s[st]]--;
                if(n[s[st]]<m[s[st]])
                {
                    now--;
                }
                st++;
            }
            e++;
        }
        if(ans==1e9)return "";
        for(int i=fs;i<=fe;i++)
        {
           fin+=s[i];
        }
        return fin;
    }
};