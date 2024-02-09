int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
class Solution {
public:
       void dfs(vector<vector<int>>&image,int i,int j,int oc,int &change)
       {
           image[i][j]=change;
            
            for(int k=0;k<4;k++)
            {
                int x=i+dx[k],y=j+dy[k];
                if(x>=0 and x<n and y>=0 and y<m and image[x][y]==oc)
                {
                     dfs(image,x,y,oc,change);
                }
            }
       }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size(),m=image[0].size();
        // vector<vector<int>>visited(n,vector<int>(m,0));
        if(image[sr][sc]==color)return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};