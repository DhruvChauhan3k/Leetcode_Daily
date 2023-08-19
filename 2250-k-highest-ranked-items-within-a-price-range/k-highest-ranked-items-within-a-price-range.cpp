vector<vector<int>>gr;
bool comp(vector<int>&a,vector<int>&b)
{
    if(a[0]==b[0])
    {
        if(gr[a[1]][a[2]]==gr[b[1]][b[2]])
        {
            if(a[1]==b[1])
            {
                return a[2]<b[2];
            }
            return a[1]<b[1];
        }
        return gr[a[1]][a[2]]<gr[b[1]][b[2]];
    }
    return a[0]<b[0];
}
class Solution {
public:
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        // int yu=k;
        gr=grid;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{start[0],start[1]}});
        vector<vector<int>>check;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        vector<vector<int>>visit(grid.size(),vector<int>(grid[0].size(),-1));
        visit[start[0]][start[1]]=1;
        if(grid[start[0]][start[1]]>1 and grid[start[0]][start[1]]>=pricing[0] and grid[start[0]][start[1]]<=pricing[1])check.push_back({0,start[0],start[1]});
        while(!q.empty())
        {
            int dis=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k],y=j+dy[k];
                if(x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y]!=0 and visit[x][y]==-1)
                {
                    if(grid[x][y]==1 or grid[x][y]<pricing[0] or grid[x][y]>pricing[1])
                    {
                        q.push({dis+1,{x,y}});
                    }
                    else
                    {
                        q.push({dis+1,{x,y}});
                        check.push_back({dis+1,x,y});
                    }
                    visit[x][y]=1;
                }
            }
        }
        sort(check.begin(),check.end(),comp);
        vector<vector<int>>ans;
        int cnt=0;
        for(auto it:check)
        {
            if(cnt==k)break;
            ans.push_back({it[1],it[2]});
            cnt++;
        }
        return ans;
    }
};