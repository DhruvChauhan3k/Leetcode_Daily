class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        // vector<int>ans;
        int x;
        for(int i=0;i<k;i++)
        {
            x=pq.top();
            // ans.push_back(x);
            pq.pop();
        }
        return x;
    }
};