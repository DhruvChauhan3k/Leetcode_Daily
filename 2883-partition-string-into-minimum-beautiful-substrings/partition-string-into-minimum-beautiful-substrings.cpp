class Solution {
public:
int ans;
    unordered_map<long long,long long>m;
    long long make(string s)
    {
        long long pow=1,ans=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            ans+=(pow*(s[i]-'0'));
            pow=pow*10;
        }
        return ans;
    }
    void gain()
    {
        m[1]++;
        long long k=1;
        for(int i=1;i<=15;i++)
        {
            k=k*5;
            m[k]++;
        }
    }
    bool take(string s)
    {
        long long ans=0,pow=1;
        long long x=make(s);
        while(x>0)
        {
            ans=ans+((pow)*(x%10));
            x=x/10;
            pow=pow*2;
        }
        if(m.find(ans)!=m.end())return true;
        return false;
    }
    void check(string ne,int i,string s,int tmp)
    {
        
        if(i==s.size())
        {
            if(ne.size()==0 or take(ne)==true)
            {
            ans=min(ans,tmp);
            }
            return;
        }
        if(ne.size()==0 and s[i]=='0')return;
        ne+=s[i];
        if(take(ne))
        {
            check("",i+1,s,tmp+1);
        }
        check(ne,i+1,s,tmp);
    }
    int minimumBeautifulSubstrings(string s) {
        m.clear();
        gain();
        ans=INT_MAX;
        string ne;
        check(ne,0,s,1);
        return ans==INT_MAX?-1:ans;
    }
};