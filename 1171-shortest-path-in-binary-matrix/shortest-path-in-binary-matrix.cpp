class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0] or grid[n-1][m-1])return -1;
        if(n==1 and m==1)return 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        int dx[]={1,1,-1,-1,0,0,-1,1};
        int dy[]={0,-1,1,-1,1,-1,0,1};
        while(!q.empty())
        {
           int x=q.front().first;
           int y=q.front().second;
           q.pop();
           for(int k=0;k<8;k++)
           {
              int i=x+dx[k],j=y+dy[k];
              if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==0 and dist[i][j]==1e9)
              {
                  if(i==n-1 and j==m-1)return dist[x][y]+1;
                  dist[i][j]=1+dist[x][y];
                  q.push({i,j});
              }
           }
        }
        return -1;
    }
};