class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        int curr=0,ans=0;
        for(auto it:nums)m[it]++;
        for(auto it:nums)
        {
            if(m.find(it-1)==m.end())
            {
                curr++;
                while(m.find(it+1)!=m.end())
                {
                    curr++;
                    it++;
                }
                ans=max(ans,curr);
                curr=0;
            }
        }
        return ans;
    }
};