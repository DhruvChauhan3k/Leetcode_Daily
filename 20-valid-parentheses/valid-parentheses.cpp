class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s)
        {
            if(it==')' and (!st.empty() and st.top()=='('))st.pop();
            else if(it=='}' and (!st.empty() and st.top()=='{'))st.pop();
            else if(it==']' and (!st.empty() and st.top()=='['))st.pop();
            else st.push(it);
        }
        return st.empty();
    }
};