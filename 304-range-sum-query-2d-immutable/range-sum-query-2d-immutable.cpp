vector<vector<int>>dp(2000,vector<int>(2000,0));
class NumMatrix {
public:
    
    NumMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                dp[i][j]=matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row2+1][col1]-dp[row1][col2+1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */