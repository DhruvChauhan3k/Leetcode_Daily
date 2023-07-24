class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size()/3+1;
        unordered_map<int,int>m;
        for(auto it:nums)
        {
            m[it]++;
            if(m[it]==n)ans.push_back(it);
        }
        return ans;
    }
};