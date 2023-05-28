class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) 
    {
        vector<int>color(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto it:d)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++)
        {
        if(color[i]!=0)continue;
        queue<int>q;
        q.push(i);
        color[i]=-1;
        while(!q.empty())
        {
            int a=q.front();
            int b=color[a];
            q.pop();
            for(auto it:adj[a])
            {
                if(color[it]==0)
                {
                    q.push(it);
                    color[it]=b*-1;
                }
                else
                {
                    if(color[it]==b)return false;
                }
            }
        }
        }
        return true;
    }
};