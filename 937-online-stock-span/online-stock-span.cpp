class StockSpanner {
public:
stack<pair<int,int>>st;
int curr;
    StockSpanner() {
        curr=0;
    }
    int next(int price) {
        while(!st.empty() and st.top().first<=price)st.pop();
        if(st.empty())
        {
            st.push({price,curr});
            curr++;
            return curr;
        }
        else
        {
            int tmp=curr-st.top().second;
            st.push({price,curr});
            curr++;
            return tmp;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */