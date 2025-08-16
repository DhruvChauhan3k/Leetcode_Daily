//memoization
class Solution {
    int[] dp;
    private int dfs(int[][] intervals, int prev_end , int curr_ind){
        if(curr_ind >= intervals.length){
            return 0;
        }
        if(dp[curr_ind] != -1)
            return dp[curr_ind];

        int picked = Integer.MIN_VALUE;

        if(intervals[curr_ind][0] >= prev_end){
            picked = 1 + dfs(intervals, intervals[curr_ind][1], curr_ind + 1);
        }
        int not_picked = dfs(intervals, prev_end, curr_ind + 1);

        return dp[curr_ind] = Math.max(picked, not_picked);
    }
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> a[1] - b[1]);
        int n = intervals.length;
         dp = new int[n];
        Arrays.fill(dp, -1);

        return n - dfs(intervals, Integer.MIN_VALUE, 0);
    }
}