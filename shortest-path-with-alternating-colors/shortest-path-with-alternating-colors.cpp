class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        vector<int>distr(n,1e9);
        vector<int>distb(n,1e9);
        vector<vector<int>>ar(n);
        vector<vector<int>>ab(n);
        for(auto it:r)
        {
            ar[it[0]].push_back(it[1]);
        }
        for(auto it:b)
        {
            ab[it[0]].push_back(it[1]);
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        distr[0]=0;
        distb[0]=0;
        while(!q.empty())
        {
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            if(b!=1)
            {
               for(auto it:ab[a])
               {
                   if(distr[a]+1<distb[it])
                   {
                       distb[it]=distr[a]+1;
                       q.push({it,1});
                   }
               }
            }
            if(b!=-1)
            {
               for(auto it:ar[a])
               {
                   if(distb[a]+1<distr[it])
                   {
                       distr[it]=distb[a]+1;
                       q.push({it,-1});
                   }
               }
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=min(distr[i],distb[i]);
            if(ans[i]==1e9)ans[i]=-1;
        }
        return ans;
    }
};