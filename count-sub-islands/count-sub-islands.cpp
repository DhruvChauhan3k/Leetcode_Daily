class Solution {
public:
void check(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool &ask)
{
    if(i<0 or j<0 or i>=grid2.size() or j>=grid2[0].size())return;
    if(grid1[i][j]==0 and grid2[i][j]==0)return;
    if(grid1[i][j]==1 and grid2[i][j]==0)return;
    if(grid2[i][j]==1 and grid1[i][j]==0)ask=false;
    grid2[i][j]=0;
    check(i+1,j,grid1,grid2,ask);
    check(i,j+1,grid1,grid2,ask);
    check(i-1,j,grid1,grid2,ask);
    check(i,j-1,grid1,grid2,ask);
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size(),m=grid2[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 and grid1[i][j]==1)
                {
                    bool ask=true;
                    check(i,j,grid1,grid2,ask);
                    if(ask==true)ans++;
                }
            }
        }
        return ans;
    }
};