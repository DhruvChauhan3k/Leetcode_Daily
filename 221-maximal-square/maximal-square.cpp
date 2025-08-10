class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>check(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int ans=0;
        for(int i=1;i<matrix.size()+1;i++)
        {
            for(int j=1;j<matrix[0].size()+1;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    int a=1+min(check[i-1][j],min(check[i][j-1],check[i-1][j-1]));
                    check[i][j]=a;
                    ans=max(ans,check[i][j]);
                }
            }
        }
        return ans*ans;
    }
};