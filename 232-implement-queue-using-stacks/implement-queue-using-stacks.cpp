class MyQueue {
public:
stack<int>st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // st.push(x);
        // stack<int>st2;
        while(!st1.empty())
        {
          int xi=st1.top();
          st2.push(xi);
          st1.pop();
        }
        st1.push(x);
        while(!st2.empty())
        {
            int xi=st2.top();
            st1.push(xi);
            st2.pop();
        }
    }
    
    int pop() {
        int xi=st1.top();
        st1.pop();
        return xi;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */