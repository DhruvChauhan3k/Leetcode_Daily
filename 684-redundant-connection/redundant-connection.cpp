class Solution {
public:
    int parent(int n,vector<int>par)
    {
        if(n==par[n])
        {
            return n;
        }
       return par[n]=parent(par[n],par);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>par(1001,0);
        for(int i=0;i<par.size();i++)par[i]=i;
        for(auto it:edges)
        {
            int x=it[0],y=it[1];
            int p1=parent(x,par);
            int p2=parent(y,par);
            if(p1==p2)
            {
                return it;
            }
            par[p1]=p2;
        }
        return {};
    }
};