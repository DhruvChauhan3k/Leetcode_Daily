class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(heights.size(),vector<int>(heights[0].size(),1e9));
        dist[0][0]=0;
        while(!pq.empty())
        {
            auto src=pq.top().second;
            int disit=pq.top().first;
            pq.pop();
            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};
            for(int i=0;i<4;i++)
            {
                int x=src.first+dx[i];
                int y=src.second+dy[i];
                if(x>=0 and x<heights.size() and y>=0 and y<heights[0].size() and max(disit,abs(heights[x][y]-heights[src.first][src.second]))<dist[x][y] )
                {
                   dist[x][y]=max(disit,abs(heights[x][y]-heights[src.first][src.second]));
                   pq.push({dist[x][y],{x,y}});
                }
            }
        }
        return dist[heights.size()-1][heights[0].size()-1];
    }
};