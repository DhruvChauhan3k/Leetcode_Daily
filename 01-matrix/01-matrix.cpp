class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
          priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        while(!q.empty())
        {
            int dis=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            int i[]={1,-1,0,0};
            int j[]={0,0,1,-1};
            for(int k=0;k<4;k++)
            {
                if(x+i[k]>=0 and x+i[k]<n and y+j[k]>=0 and y+j[k]<m)
                {
                    if(dis+1<dist[x+i[k]][y+j[k]])
                    {
                        dist[x+i[k]][y+j[k]]=dis+1;
                        q.push({dis+1,{x+i[k],y+j[k]}});
                    }
                }
            }

        }
        return dist;
    }
};
