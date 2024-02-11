class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>v(n,0);
        vector<int>order;
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                v[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                q.push(i);
                order.push_back(i);
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
                    order.push_back(it);
                }
            }
        }
        sort(order.begin(),order.end());
        return order;
    }
};