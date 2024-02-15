class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        vector<long long>x;
        for(auto it:nums)
        {
            x.push_back((long long)it);
        }
        for(int i=0;i<x.size();i++)
        {
            x[i]=sum+nums[i];
            sum=x[i];
        }
        long long maxi=-1;
        for(int i=2;i<x.size();i++)
        {
            if(x[i]-nums[i]>nums[i])maxi=x[i];
        }
        return maxi;
    }
};