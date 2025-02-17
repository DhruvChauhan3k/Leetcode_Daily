class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int it=nums[i];
            if(m.find(target-it)!=m.end())return {m[target-it],i};
            m[it]=i;
        }
        return {-1,-1};
    }
};