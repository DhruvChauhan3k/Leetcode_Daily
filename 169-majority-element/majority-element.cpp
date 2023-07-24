class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(auto it:nums)
        {
            m[it]++;
            if(m[it]>n/2)return it;
        }
        return 0;
    }
};