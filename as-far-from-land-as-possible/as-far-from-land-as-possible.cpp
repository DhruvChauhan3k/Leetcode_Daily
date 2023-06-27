class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,-1));
        int ans=-1;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {

                q.push({i,j});
                dist[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};
            for(int i=0;i<4;i++)
            {
                int a=x+dx[i],b=y+dy[i];
                if(a>=0 and a<n and b>=0 and b<n and dist[a][b]==-1)
                {
                    q.push({a,b});
                    dist[a][b]=1+dist[x][y];
                    ans=max(ans,dist[a][b]);
                }
            }

        }
        return ans;
    }
};