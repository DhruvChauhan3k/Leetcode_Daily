class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int now=1e9;
        int sum=0;
        for(auto it:prices)
        {
            if(it>now)
            {
                sum+=(it-now);
                now=it;
            }
            else
            {
                now=it;
            }
        }
        return sum;
    }
};