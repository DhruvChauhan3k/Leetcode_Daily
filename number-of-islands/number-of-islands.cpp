class Solution {
public:
 
    void dfs(int i,int j,vector<vector<char>>& grid)
    {
        if(i>=grid.size() or i<0 or j<0 or j>=grid[0].size() or grid[i][j]-'0'==0)return;
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]-'0'==1)
                {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};