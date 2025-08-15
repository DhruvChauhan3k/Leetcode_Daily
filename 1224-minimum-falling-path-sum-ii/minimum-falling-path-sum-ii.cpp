class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If n == 1, the answer is just the minimum in that single row.
        if (n == 1) return *min_element(grid[0].begin(), grid[0].end());


        auto findTwoMins = [&](const vector<int>& arr) {
            // returns {minVal, minIdx, secondMinVal}
            int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;
            for (int j = 0; j < (int)arr.size(); ++j) {
                int v = arr[j];
                if (v < min1) { min2 = min1; min1 = v; idx1 = j; }
                else if (v < min2) { min2 = v; }
            }
            return tuple<int,int,int>(min1, idx1, min2);
        };

        // smallest and second smallest for row 0
        auto [prevMin, prevIdx, prevSecond] = findTwoMins(grid[0]);

        for (int i = 1; i < n; ++i) {
            vector<int> ndp(m);
            for (int j = 0; j < m; ++j) {
                int bestPrev = (j == prevIdx ? prevSecond : prevMin);
                ndp[j] = grid[i][j] + bestPrev;
            }
            // dp.swap(ndp);
            tie(prevMin, prevIdx, prevSecond) = findTwoMins(ndp);
            if(i==n-1)return prevMin;
        }

        return -1;
    }
};
