class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int prev=-1e9;
        for(int i=0;i<nums.size();i++){
          int mini=nums[i]-k;
          int maxi=nums[i]+k;
          if(prev<mini){prev=mini;ans++;}
          else if(prev<maxi){prev++;ans++;}
        }
        return ans;
    }
};