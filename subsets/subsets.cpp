class Solution {
public:
void check(vector<vector<int>>&ans,vector<int>temp,int i,vector<int>&nums)
{
    if(i==nums.size())
    {
        ans.push_back(temp);
        return;
    }
    check(ans,temp,i+1,nums);
    temp.push_back(nums[i]);
    check(ans,temp,i+1,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        check(ans,temp,0,nums);
        return ans;
    }
};