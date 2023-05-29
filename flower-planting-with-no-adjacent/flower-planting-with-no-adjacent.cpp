class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        vector<int>color(n+1,0);
        for(auto it:paths)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++)
        {
        if(color[i]==0)
        {
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
           int a=q.front();
           q.pop();
           vector<int>check(5,0);
           for(auto it:adj[a])
           {
               if(color[it]!=0)check[color[it]]=1;
               else if(color[it]==0)
               {
                   q.push(it);
               }
           }
           for(int i=1;i<5;i++)
           {
               if(check[i]==0)
               {
                  color[a]=i;
                  break;
               }
           }
        }
        }
        }
        vector<int>ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(color[i]);
        }
        return ans;
    }
};