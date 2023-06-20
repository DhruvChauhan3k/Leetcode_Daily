class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long long int>pre;
        int n=nums.size();
        long long int now=0;
        for(auto it:nums)
        {
            now+=it;
            pre.push_back(now);
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(i-k<0 or i+k>=n)continue;
            long long int curr=pre[i+k];
            if(i-k-1>=0)curr-=pre[i-k-1];
            ans[i]=curr/(k+k+1);
        }
        return ans;
    }
};