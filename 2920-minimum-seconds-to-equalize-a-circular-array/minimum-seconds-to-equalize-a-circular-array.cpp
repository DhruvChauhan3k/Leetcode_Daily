class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        vector<int>a=nums;
        for(auto it:a)
        {
            nums.push_back(it);
        }
        unordered_map<int,int>m,n;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                int now=i-m[nums[i]]-1;
                n[nums[i]]=max(n[nums[i]],now);
            }
            m[nums[i]]=i;
        }
        for(auto it:n)
        {
            ans=min(ans,it.second);
        }
        return (ans+1)/2;
    }
};