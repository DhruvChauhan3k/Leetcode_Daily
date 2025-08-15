class Solution {
public:
    int n, m;
    vector<vector<int>> grid;
    vector<vector<int>> dp;

    // Precomputed per row
    vector<int> rowMin, rowMinIdx, rowSecond;

    int solve(int i, int j) {
        if (i == n - 1) return grid[i][j]; // base case

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int bestNext;
        if (j == rowMinIdx[i + 1]) bestNext = rowSecond[i + 1];
        else bestNext = rowMin[i + 1];

        return dp[i][j] = grid[i][j] + bestNext;
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        grid = mat;
        n = mat.size();
        m = mat[0].size();
        dp.assign(n, vector<int>(m, INT_MAX));

        rowMin.resize(n);
        rowMinIdx.resize(n);
        rowSecond.resize(n);

        // Base case row: last row's min/second min is itself
        for (int j = 0; j < m; j++) dp[n - 1][j] = grid[n - 1][j];

        // Precompute rowMin/rowSecond for all rows starting from bottom
        for (int i = n - 1; i >= 0; i--) {
            int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;
            for (int j = 0; j < m; j++) {
                int v = dp[i][j];
                if (v < min1) { min2 = min1; min1 = v; idx1 = j; }
                else if (v < min2) min2 = v;
            }
            rowMin[i] = min1;
            rowMinIdx[i] = idx1;
            rowSecond[i] = min2;
            if (i > 0) { // Fill dp[i-1] using solve
                for (int j = 0; j < m; j++) dp[i - 1][j] = solve(i - 1, j);
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};
