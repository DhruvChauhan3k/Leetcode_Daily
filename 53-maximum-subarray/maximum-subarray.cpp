class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN,curr=0;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            maxi=max(curr,maxi);
            if(curr<0)
            {
                curr=0;
            }
        }
        return maxi;
    }
};