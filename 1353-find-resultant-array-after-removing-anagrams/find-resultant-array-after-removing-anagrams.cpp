class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       unordered_map<string,int>m;
        int i=0;
        vector<string>ans;
       for(auto it:words)
       {
           sort(it.begin(),it.end());
           if(m.find(it)==m.end() or m[it]!=i-1)
           {
               ans.push_back(words[i]);
           }
           m[it]=i;
           i++;
       }
        return ans;
    }
};