class Solution {
public:
int ans=INT_MAX;
    void check(int i,vector<int>&cookies,vector<int>&child)
    {
        if(i==cookies.size())
        {
            int now=0;
            for(auto it:child)now=max(now,it);
            if(now<ans)ans=now;
            return;
        }
        for(int k=0;k<child.size();k++)
        {
            child[k]+=cookies[i];
            check(i+1,cookies,child);
            child[k]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        check(0,cookies,child);
        return ans;
    }
};