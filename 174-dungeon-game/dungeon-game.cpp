class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>>& dungeon) {
        // Out of bounds → impossible, return large value
        if (i >= m || j >= n) return INT_MAX;

        // If already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Base case: princess cell (bottom-right)
        if (i == m - 1 && j == n - 1) {
            return dp[i][j] = max(1, 1 - dungeon[i][j]);
        }

        // Recursive calls → go right or down
        int right = dfs(i, j + 1, dungeon);
        int down  = dfs(i + 1, j, dungeon);

        // Choose min health needed from right or down
        int need = min(right, down) - dungeon[i][j];

        // Store and return
        return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        dp.assign(m, vector<int>(n, -1));

        return dfs(0, 0, dungeon);
    }
};
