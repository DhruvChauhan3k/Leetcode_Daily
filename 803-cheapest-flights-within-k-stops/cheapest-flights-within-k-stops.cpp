class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
          vector<pair<int,int>>adj[n];
       for(auto it:flights)
       {
           adj[it[0]].push_back({it[1],it[2]});
       }
       queue<pair<int,pair<int,int>>> q;
       q.push({0,{src,0}});
       vector<int>dis(n,1e9);
       dis[src]=0;
       int ans=-1; 
       while(!q.empty())
    {
        auto it=q.front();
        int node=it.second.first;
        int stops=it.first;
        int dist=it.second.second;
        q.pop();
        for(auto i:adj[node])
        {   
            int w=i.second;
            int n=i.first;
            if(dist+w< dis[n] and stops<=K )
            {
                dis[n]=dist+w;
                q.push({stops+1,{n,dis[n]}});
            }
        }
        
        
    }
    if(dis[dst]==1e9) return -1;
    return dis[dst];
    }
};