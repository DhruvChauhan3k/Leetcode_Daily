class Solution {
public:
vector<vector<int>>ik;
void check(vector<vector<int>>& grid, int i, int j, int c,vector<vector<int>>&visit)
{
    if(visit[i][j]==1)return;
    visit[i][j]=1;
    bool chec=false;
    if(i+1<grid.size() and ik[i+1][j]==ik[i][j])
    {
        check(grid,i+1,j,c,visit);
    }
    else
    {
        chec=true;
    }
    if(j+1<grid[0].size() and ik[i][j+1]==ik[i][j])
    {
        check(grid,i,j+1,c,visit);
    }
    else
    {
        chec=true;
    }
    if(i-1>=0 and ik[i-1][j]==ik[i][j])
    {
        check(grid,i-1,j,c,visit);
    }
    else
    {
        chec=true;
    }
    if(j-1>=0 and ik[i][j-1]==ik[i][j])
    {
        check(grid,i,j-1,c,visit);
    }
    else
    {
        chec=true;
    }
    if(chec==true)grid[i][j]=c;
}
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int i, int j, int c) {
        vector<vector<int>>visit(grid.size(),vector<int>(grid[0].size(),-1));
        ik=grid;
        check(grid,i,j,c,visit);
        return grid;
    }
};