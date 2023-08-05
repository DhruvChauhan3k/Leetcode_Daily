class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        stack<int>ind;
        int ans=0;
        ind.push(-1);
        for(int i=0;i<s.size();i++)
        {
            char it=s[i];
            if(it==')')
            {
               if(!st.empty() and st.top()=='(')
               {
                   ind.pop();
                   st.pop();
                   ans=max(ans,(i-ind.top()));
               }
               else
               {
                   st.push(')');
                   ind.push(i);
               }
            }
            else
            {
                ind.push(i);
                st.push(it);
            }
        }
        return ans;
    }
};