class Solution {
public:
    int get(int i,int j,vector<vector<int>>& grid,int n,int m)
    {
        grid[i][j]=0;
        int dy[]={0,0,1,-1};
        int dx[]={1,-1,0,0};
        int ans=1;
        for(int l=0;l<4;l++)
        {
            int x=i+dx[l];
            int y=j+dy[l];
            if(x>=0 and x<n and y>=0 and y<m and grid[x][y]==1)
            {
                ans+=get(x,y,grid,n,m);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,get(i,j,grid,n,m));
                }
            }
        }
        return ans;
    }
};