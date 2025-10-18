class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int knew = k-1;
        if(knew <= 0)return true;
        for(int j=k+1;j<nums.size();j++){
            if(nums[j] > nums[j-1] && nums[j-k] > nums[j-k-1])knew--;
            else knew = k - 1;
            if(knew == 0)return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
             int s=0,e=nums.size()/2,ans=0;
             while(s<=e){
                int mid=s+(e-s)/2;
                if(hasIncreasingSubarrays(nums,mid)){
                    s=mid+1;
                    ans=max(ans,mid);
                }
                else
                {
                    e=mid-1;
                }
             }
             return ans;

    }
};