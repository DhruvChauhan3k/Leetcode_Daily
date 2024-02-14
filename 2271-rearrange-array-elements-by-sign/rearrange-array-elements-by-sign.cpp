class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int pos=0,neg=0;
        while(pos<n or neg<n)
        {
            if(pos<n)
            {
                while(pos<n and nums[pos]<0)pos++;
                if(pos<n)
                {
                    ans.push_back(nums[pos]);
                    pos++;
                }
            }
            if(neg<n)
            {
                while(neg<n and nums[neg]>0)neg++;
                if(neg<n)
                {
                  ans.push_back(nums[neg]);
                  neg++;
                }
            }
        }
        return ans;
    }
};