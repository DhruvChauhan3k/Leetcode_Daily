int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                grid[i][0]=2;
            }
            if(grid[i][m-1]==1)
            {
              q.push({i,m-1});
              grid[i][m-1]=2;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
            {
                q.push({0,i});
                grid[0][i]=2;
            }
            if(grid[n-1][i]==1)
            {
                q.push({n-1,i});
                grid[n-1][i]=2;
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int i=x+dx[k],j=y+dy[k];
                if(i>=0 and j>=0 and i<n and j<m and grid[i][j]==1)
                {
                    grid[i][j]=2;
                    q.push({i,j}); 
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)ans++;
            }
        }
        return ans;

    }
};