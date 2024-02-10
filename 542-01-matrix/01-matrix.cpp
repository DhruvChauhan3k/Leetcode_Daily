int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    visited[i][j]=1;
                    q.push({i,j});
                }
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
                if(i>=0 and j>=0 and i<n and j<m and visited[i][j]==0)
                {
                    visited[i][j]=1;
                    dist[i][j]=1+dist[x][y];
                    q.push({i,j});
                }
            }
        }
        return dist;
    }
};