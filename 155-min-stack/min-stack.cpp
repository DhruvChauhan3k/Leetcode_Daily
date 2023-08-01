class MinStack {
public:
    vector<int>s;
    vector<int>min;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);
        if(min.empty() or val<=getMin())
        {
            min.push_back(val);
        }
    }
    void pop() {
        if(s[s.size()-1]==getMin())
        {
        min.pop_back();
        }
        s.pop_back();
    }
    
    int top() {
        return s[s.size()-1];
    }
    
    int getMin() {
        return min[min.size()-1];
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