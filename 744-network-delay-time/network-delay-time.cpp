class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);
        dist[0]=0;
        dist[k]=0;
        while(!pq.empty())
        {
            int x=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:adj[x])
            {
                if(dist[it.first]>dis+it.second)
                {
                    dist[it.first]=dis+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int ans=0;
        for(auto it:dist)
        {
            ans=max(ans,it);
        }
        return ans==1e9?-1:ans;
    }
};