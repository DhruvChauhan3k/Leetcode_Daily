class Solution {
public:
    void check(vector<int>&visit,vector<int>&now,vector<int>&ans,int i,vector<vector<int>>&adj)
    {
        now[i]=1;
        visit[i]=1;
        for(auto it:adj[i])
        {
            if(now[it]==1)
            {
                ans.clear();
                return;
            }
            if(visit[it]==-1)
            {
                check(visit,now,ans,it,adj);
                if(ans.size()==0)
                {
                    return ;
                }
            }
        }
        now[i]=-1;
        ans.push_back(i);
        return;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(auto it:pre)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int>visit(n,-1);
        vector<int>now(n,-1);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(visit[i]==-1)
            {
                check(visit,now,ans,i,adj);
                if(ans.empty())
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};