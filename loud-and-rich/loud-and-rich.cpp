class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for(auto it:richer)
        {
            int x=it[0],y=it[1];
            degree[y]++;
            adj[x].push_back(y);
        }
        queue<pair<int,int>>q;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(degree[i]==0)
            {
                q.push({i,i});
            }
        }
        while(!q.empty())
        {
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            for(auto it:adj[a])
            {
                degree[it]--;
                    int c=ans[it];
                    if(quiet[c]>quiet[ans[b]])
                    {
                        c=ans[b];
                    }
                    ans[it]=c;
                if(degree[it]==0)q.push({it,it});
            }
        }
        return ans;
    }
};