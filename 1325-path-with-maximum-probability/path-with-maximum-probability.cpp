class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        vector<int>visit(n,0);
        visit[start_node]=1;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>prob(n,0);
        prob[start_node]=1;
        pq.push({1.0000,start_node});
        while(!pq.empty())
        {
           double p=pq.top().first;
           int x=pq.top().second;
           pq.pop();
           if(x==end_node)return p;
           for(auto it:adj[x])
           {
            if(visit[it.first]==0 or p*it.second>prob[it.first])
            {
                pq.push({p*it.second,it.first});
                visit[it.first]=1;
                prob[it.first]=p*it.second;
            }
           }
        }
        return 0.0000;
    }
};