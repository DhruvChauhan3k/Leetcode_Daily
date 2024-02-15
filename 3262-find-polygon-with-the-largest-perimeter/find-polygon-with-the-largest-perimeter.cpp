class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        vector<long long>x;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            x.push_back(sum);
        }
        long long maxi=-1;
        for(int i=2;i<x.size();i++)
        {
            if(x[i]-nums[i]>nums[i])maxi=x[i];
        }
        return maxi;
    }
};