class MinStack {
public:
    stack<int>st;
    stack<int>mini;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(mini.empty() or val<=mini.top())
        {
           mini.push(val);
        }
    }
    
    void pop() {
        int x=st.top();
        st.pop();
        if(x==mini.top())mini.pop();
    }
    
    int top() {
       return st.top();
    }
    
    int getMin() {
         return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */