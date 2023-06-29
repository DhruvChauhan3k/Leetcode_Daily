int dx[]={1,-1,0,0};
   int dy[]={0,0,1,-1};
   int n,m;
class Solution {
public:
   
    int check(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=n or i<0 or j<0 or j>=m or grid[i][j]==0)return 0;
        int ans=0;
        int x=grid[i][j];
        grid[i][j]=0;
        for(int k=0;k<4;k++)
        {
             ans=max(ans,x+check(i+dx[k],j+dy[k],grid));
        }
        grid[i][j]=x;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,check(i,j,grid));
            }
        }
        return ans;
    }
};