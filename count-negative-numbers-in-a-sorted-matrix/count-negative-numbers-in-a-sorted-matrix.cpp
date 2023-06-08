class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=0,c=0;
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        c=m-1;
        while(r<n and c>=0)
        {
          if(grid[r][c]<0)c--;
          else
          {
              ans+=m-c-1;
              r++;
          }
        }
        if(c<0 and r<n)ans+=(n-r)*m;
        return ans;
    }
};