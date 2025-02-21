class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>v(n,0);
        vector<vector<int>>adj(n);
        queue<int>q;
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
            v[it[0]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
           int x=q.front();
           q.pop();
           for(auto it:adj[x])
           {
               v[it]--;
               if(v[it]==0)
               {
                   q.push(it);
               }
           }
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]!=0)return false;
        }
        return true;
    }
};