class Solution {
public:
int dp[100003][3];
    int maxDec(vector<int>& nums1, vector<int>& nums2, int prev ,int i){
        int n = nums1.size();
        if(i >= n){
            return 0;
        }
        if(dp[i][prev] != -1){
            return dp[i][prev];
        }
        int nopick = 0;     
        int pick1 = 0;
        int pick2 = 0;
        if(prev == 0){
        nopick = maxDec(nums1,nums2,prev,i+1);
        }
        int val;
        if(prev == 0){
            val = 0; // in this case nums1[i] > val and nums2[i] > val
        }
        else if(prev == 1){
            val = nums1[i-1];
        }
        else{
            val = nums2[i-1];
        }
        if(nums1[i] >= val){
            pick1 = 1 + maxDec(nums1,nums2,1,i+1);
        }
        if(nums2[i] >= val){
                pick2 = 1 + maxDec(nums1,nums2,2,i+1);
        }
        return dp[i][prev] = max({pick1,pick2,nopick});
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        // this is a simple pick not pick pattern 
        int n = nums1.size();
       int prev = -1;
       // now see while doing dp we cannot store prev bcoz prev might range till 1e9 
       // so we will store prev -> 0 subarray size is 0 
       // prev-> 1 last element from nums1
       // prev -> 2 last element from nums2 
        memset(dp,-1,sizeof(dp));
        return maxDec(nums1,nums2,0,0);
    }
};