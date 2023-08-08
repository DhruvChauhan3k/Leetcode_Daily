class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=1,curr=1;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])curr++;
            else curr=1;
            ans=max(ans,curr);
        }
        return ans;
    }
};