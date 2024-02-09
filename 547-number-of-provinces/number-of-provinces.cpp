class Solution {
public:
    int findCircleNum(vector<vector<int>>& roads) {
        int n=roads.size();
        vector<vector<int>>adj(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(roads[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>visit(n,0);
    int ans=0;
    for(int i=0;i<n;i++)
    { 
        if(visit[i]==1)continue;
        ans++;
        queue<int>q;
        q.push(i);
        visit[i]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it:adj[x])
            {
                if (visit[it] == 0) 
                {
                  q.push(it);
                  visit[it] = 1;
                }
            }
        }

    }
    return ans;
    }
};