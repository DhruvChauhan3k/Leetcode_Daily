class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int a,b;
        for(auto it:tokens)
        {
            if(it=="+")
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(a+b);
            }
            else if(it=="-")
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(it=="*")
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(a*b);
            }
            else if(it=="/")
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b/a);
            }
            else
            {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};