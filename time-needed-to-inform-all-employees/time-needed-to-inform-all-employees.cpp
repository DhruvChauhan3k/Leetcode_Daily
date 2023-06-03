class Solution {
public:
    int check(int h,vector<vector<int>>&adj,vector<int>&it)
    {
        int ans=0;
        for(auto i:adj[h])
        {
            ans=max(ans,it[h]+check(i,adj,it));
        }
        return ans;
    }
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& it) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            if(m[i]==-1)continue;
            adj[m[i]].push_back(i);
        }
        int ans=0;
        return check(h,adj,it);
    }
};