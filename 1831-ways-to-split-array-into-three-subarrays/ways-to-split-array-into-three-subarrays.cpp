class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        int ans = 0;
        int mod = 1e9 + 7; // ERROR 1: Correct Modulo constant
        
        // ERROR 2: Loop limit. We need at least 2 elements after i 
        // (1 for mid, 1 for right). So i stops at n-3.
        for(int i = 0; i < n - 2; i++) {
            
            // Optimization: If left part is > 1/3 of total, no solution possible anymore
            if (pre[i] > pre[n-1] / 3) break; 
            
            // Find the Lower Bound for the 2nd cut
            // We search in range [i+1, n-2] (index n-1 is reserved for Right subarray)
            auto search_end = pre.begin() + n - 1; 
            
            int st = lower_bound(pre.begin() + i + 1, search_end, 2 * pre[i]) - pre.begin();
            
            // Find the Upper Bound for the 2nd cut
            // Condition: pre[j] <= (Total + pre[i]) / 2
            int see = (pre[n-1] - pre[i]) / 2 + pre[i];
            int up = upper_bound(pre.begin() + i + 1, search_end, see) - pre.begin();
            
            // ERROR 3: Ensure we don't add negative numbers
            if (up > st) {
                ans = (ans + (up - st)) % mod;
            }
        }
        
        return ans;
    }
};