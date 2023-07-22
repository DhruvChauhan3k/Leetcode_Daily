class Solution {
public:
    long long helper(int start, int rem, vector<int>& nums, int x, vector<vector<long long>>& dp){
        int n = nums.size();
        if(start == n){
            return 0;
        }
        
        if(dp[start][rem] != -1){
            return dp[start][rem];
        }
        
        long long notake = helper(start + 1, rem, nums, x, dp);
        
        long long take = 0;
        if(nums[start] % 2 == rem){
            take = nums[start] + helper(start + 1, rem, nums, x, dp);
        }
        else{
            take = nums[start] - x + helper(start + 1, !rem, nums, x, dp);
        }
        
        
        return dp[start][rem] = max(take, notake);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return helper(1, nums[0] % 2, nums, x, dp) + nums[0];
    }
};