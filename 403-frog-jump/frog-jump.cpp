class Solution {
public:
    
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> m;
        int n = stones.size();
        
        for (int i = 0; i < n; i++) {
            m[stones[i]] = i;  // Map stone value to index
        }
        
        if (stones[1] != 1) return false;  // The first jump must be 1
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));  // DP table



        for(int i=0;i<=n;i++){
            dp[n-1][i]=1;
        }

        for(int i=n-1;i>=1;i--){
            for(int k=n-1;k>=1;k--){

            int ans=0;
            if (dp[i][k] != -1) continue; 

            for (int step : {k - 1, k, k + 1}) {
            if (step > 0 && m.find(stones[i] + step) != m.end()) {
                int next_index = m[stones[i] + step];
                if (next_index > i) {  // Ensure we are moving forward
                    ans |= dp[next_index][step];
                }
            }
        }
        dp[i][k] = ans;
            }
        }
  
        return dp[1][1];  // Start from the second stone with a jump of 1
    }
};
