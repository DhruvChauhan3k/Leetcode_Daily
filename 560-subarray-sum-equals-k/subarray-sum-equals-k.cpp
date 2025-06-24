class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sum=0,ans=0;
        for(auto it:nums){
            sum+=it;
            if(sum==k)ans++;
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};