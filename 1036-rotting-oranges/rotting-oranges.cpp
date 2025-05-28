int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            ans=it.first;
            int i=it.second.first,j=it.second.second;
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k],y=j+dy[k];
                if(x<n and x>=0 and y<m and y>=0 and grid[x][y]==1)
                {
                    grid[x][y]=2;
                    q.push({ans+1,{x,y}});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};