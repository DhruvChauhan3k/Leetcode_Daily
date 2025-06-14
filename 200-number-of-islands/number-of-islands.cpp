class Solution {
public:
    void check(int i,int j,vector<vector<char>>&grid)
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            if(x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y]=='1')
            {
                grid[x][y]=1;
                check(x,y,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
     int n=grid.size(),m=grid[0].size();
     int ans=0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(grid[i][j]=='1')
             {
               grid[i][j]=1;
               check(i,j,grid);  
               ans++;
             }
         }
     }
     return ans;
    }
};