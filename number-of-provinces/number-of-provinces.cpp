class Solution {
public:
    void check(vector<int>&visit,vector<vector<int>>&adj,int i)
    {
        visit[i]=1;
        for(auto it:adj[i])
        {
            if(visit[it]==-1)
            {
                check(visit,adj,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& conn) {
        vector<vector<int>>adj(conn.size());
        for(int i=0;i<conn.size();i++)
        {
            for(int j=0;j<conn[0].size();j++)
            {
                if(i==j)continue;
                if(conn[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
            vector<int>visit(conn.size(),-1);
            int ans=0;
            for(int i=0;i<conn.size();i++)
            {
                if(visit[i]==-1)
                {
                    ans++;
                    check(visit,adj,i);
                }
            }
            
            return ans;
    }
};