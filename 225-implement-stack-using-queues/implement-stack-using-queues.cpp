class MyStack {
public:
queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        
    }
    
    int pop() {
        queue<int>q2;
        int temp;
        while(!q1.empty())
        {
            if(q1.size()==1)
            {
            temp=q1.front();
            q1.pop();
            continue;
            }
            temp=q1.front();
            q1.pop();
            q2.push(temp);
        }
        q1=q2;
        // q2.clear();
        return temp;
    }
    
    int top() {
        queue<int>q2;
        int temp;
        while(!q1.empty())
        {
            temp=q1.front();
            q1.pop();
            q2.push(temp);
        }
        q1=q2;
        // q2.clear();
        return temp;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */