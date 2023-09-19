class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int x;
        for(int i=0;i<nums.size();i++)
        {
            x=abs(nums[i]);
            if(nums[x]<0)
            {
                return x;
            }
            nums[x]=nums[x]*-1;
        }
        return 0;
    }
};