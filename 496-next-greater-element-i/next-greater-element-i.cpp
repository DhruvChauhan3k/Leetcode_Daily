class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() and nums2[i]>nums2[st.top()]){
                m[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int>ans;
        for(auto it:nums1){
            if(m.find(it)==m.end())ans.push_back(-1);
            else ans.push_back(m[it]);
        }
        return ans;
    }
};