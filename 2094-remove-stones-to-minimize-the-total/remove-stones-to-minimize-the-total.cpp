class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        priority_queue<int>pq(piles.begin(),piles.end());
        for(auto it:piles)
        {
            // pq.push_bak(it);
            ans+=it;
        }
        int x,y;
        for(int i=0;i<k;i++)
        {
            x=floor(pq.top()/2);
            y=pq.top()-x;
            pq.pop();
            ans-=x;
            pq.push(y);
            // ans+=floor(x/2);
        }
    return ans;
    }
};