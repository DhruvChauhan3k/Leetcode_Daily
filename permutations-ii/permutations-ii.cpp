class Solution {
public:
    void generate(vector<vector<int>>&ans,vector<int>&nums,int l,int r)
    {
        if(l>r)
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int i=l;i<=r;i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                continue;
            }
            s.insert(nums[i]);
            swap(nums[i],nums[l]);
            generate(ans,nums,l+1,r);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        // ans.push_back(nums);
        generate(ans,nums,0,nums.size()-1);
        return ans;
    }
};