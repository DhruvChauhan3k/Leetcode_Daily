class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(grid[0][0]==1)
        {
            if(k==0)return -1;
            k--;
        }
        queue<pair<int,pair<int,int>>>q;
        int ans=0;
        q.push({0,{0,k}});
        vector<vector<vector<int>>>visit(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        visit[0][0][k]=1;
        int x[]={1,-1,0,0};
        int y[]={0,0,1,-1};
        while(!q.empty())
        {
            int xk=q.size();
            for(int j=0;j<xk;j++)
            {
             int a=q.front().first;
             int b=q.front().second.first;
             int c=q.front().second.second;
             q.pop();
             if(a==grid.size()-1 and b==grid[0].size()-1)return ans;
            for(int i=0;i<4;i++)
            {
                int xi=x[i]+a;
                int yi=y[i]+b;
                if(xi>=0 and xi<grid.size() and yi>=0 and yi<grid[0].size())
                {
                  if(grid[xi][yi]==0 and visit[xi][yi][c]==-1)
                  {
                  visit[xi][yi][c]=1;
                  q.push({xi,{yi,c}});
                  }
                  else if(grid[xi][yi]==1 and c-1>=0 and visit[xi][yi][c-1]==-1)
                  {
                        visit[xi][yi][c-1]=1;
                        q.push({xi,{yi,c-1}});
                  }
                }
            }
            }
            ans++;
        }
        return -1;
    }
};