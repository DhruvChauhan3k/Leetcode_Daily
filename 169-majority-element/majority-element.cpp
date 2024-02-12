class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // vector<int>v(26,0);?
        unordered_map<int,int>m;
        int x=nums.size()/2;
        for(auto it:nums)
        {
            m[it]++;
            if(m[it]>x)return it;
        }
        return -1;
    }
};