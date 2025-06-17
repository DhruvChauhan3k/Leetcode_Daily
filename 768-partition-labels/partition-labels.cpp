class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>m;
        int i=0;
        for(auto it:s){
            m[it]=i;
            i++;
        }
        vector<int>ans;
        int curr=0;
        int fut=-1;
        int cr=0;
        for(auto it:s){
            curr++;
            fut=max(fut,m[it]);
            if(fut==cr){
                ans.push_back(curr);
                curr=0;
            }
            cr++;
        }
        return ans;
    }
};