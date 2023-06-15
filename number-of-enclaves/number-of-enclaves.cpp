class Solution {
public:
int ans;
    void dfs(int i,int j,vector<vector<int>>&grid)
    {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)return;
        grid[i][j]=0;
        ans++;
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        ans=0;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1)count++;
            }
        }
        

            for(int j=0;j<m;j++)
            {
                if(grid[0][j]==1)dfs(0,j,grid);
            }
            for(int j=0;j<n;j++)
            {
                if(grid[j][0]==1)dfs(j,0,grid);
            }
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[n-1][j]==1)dfs(n-1,j,grid);
            }
            for(int j=0;j<n;j++)
            {
                if(grid[j][m-1]==1)dfs(j,m-1,grid);
            }
            return count-ans;
    }
};