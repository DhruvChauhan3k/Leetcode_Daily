class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            int x = upper_bound(nums.begin(),nums.end(),nums[i]+k)-lower_bound(nums.begin(),nums.end(),nums[i]-k);
            int y = upper_bound(nums.begin(),nums.end(),nums[i])-lower_bound(nums.begin(),nums.end(),nums[i]-2*k);
            ans = max(ans,max(x,y));
        }
        return ans;
    }
};