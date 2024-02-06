class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(auto it:strs)
        {
            string t=it;
            sort(it.begin(),it.end());
            m[it].push_back(t);
        }
        vector<vector<string>>ans;
        for(auto it:m)
        {
            vector<string>temp;
            for(auto t:it.second)
            {
                temp.push_back(t);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};