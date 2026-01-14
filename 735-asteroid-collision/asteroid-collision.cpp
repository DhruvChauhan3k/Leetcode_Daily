class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>st;
        for(int i=0;i<a.size();i++){
            if(!st.empty() and a[i]<0){
                while(!st.empty() and st.top()<abs(a[i]) and st.top()>=0){
                    st.pop();
                }
                if(st.empty() or st.top()<0)st.push(a[i]); 
                else if(!st.empty() and st.top()==abs(a[i]))st.pop();
            }
            else{
                st.push(a[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};