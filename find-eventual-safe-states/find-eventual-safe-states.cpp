class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            degree[i]=graph[i].size();
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
            }
            if(degree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
             int a=q.front();
             ans.push_back(a);
             q.pop();
             for(auto it:adj[a])
             {
                 degree[it]--;
                 if(degree[it]==0)q.push(it);
             }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};