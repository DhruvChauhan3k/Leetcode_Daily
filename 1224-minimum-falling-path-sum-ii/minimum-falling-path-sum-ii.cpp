class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix; // copy initial
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int best = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    best = min(best, dp[i+1][k]);
                }
                dp[i][j] += best;
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};
