class Solution {
public:
    int check(int i, vector<int>& stones, vector<vector<int>>& dp, int k, unordered_map<int, int>& m) {
        if (i == stones.size() - 1) return 1;  // Reached the last stone
        
        if (dp[i][k] != -1) return dp[i][k];  // Memoization
        
        int ans = 0;
        
        // Check possible jumps
        for (int step : {k - 1, k, k + 1}) {
            if (step > 0 && m.find(stones[i] + step) != m.end()) {
                int next_index = m[stones[i] + step];
                if (next_index > i) {  // Ensure we are moving forward
                    ans |= check(next_index, stones, dp, step, m);
                }
            }
        }
        
        return dp[i][k] = ans;
    }

    bool canCross(vector<int>& stones) {
        unordered_map<int, int> m;
        int n = stones.size();
        
        for (int i = 0; i < n; i++) {
            m[stones[i]] = i;  // Map stone value to index
        }
        
        if (stones[1] != 1) return false;  // The first jump must be 1
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));  // DP table
        
        return check(1, stones, dp, 1, m);  // Start from the second stone with a jump of 1
    }
};
