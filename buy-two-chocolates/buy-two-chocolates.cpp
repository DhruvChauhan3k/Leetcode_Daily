class Solution {
public:
    int buyChoco(vector<int>& prices, int m) {
        sort(prices.begin(),prices.end());
        // int n=prices.size();
        int a=prices[0],b=prices[1];
        if(m-(a+b)>=0)return m-(a+b);
        return m;
    }
};