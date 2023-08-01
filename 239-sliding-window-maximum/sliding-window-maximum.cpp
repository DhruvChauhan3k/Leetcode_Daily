class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>q;
        int i=0;
        for(;i<k-1;i++)
        {
            while(!q.empty() and nums[i]>q.back().first)
            {
                   q.pop_back();
            }
            q.push_back({nums[i],i});
        }
        vector<int>ans;
        for(;i<nums.size();i++)
        {
             while(!q.empty() and nums[i]>q.back().first)
            {
                   q.pop_back();
            }
            q.push_back({nums[i],i});
            ans.push_back(q.front().first);
            if(q.front().second<=i+1-k)q.pop_front();
        }
        return ans;
    }
};