class Solution {
public:
    unordered_set<string> set;
    int n;
    int kSimilarity(string &s1, string &s2) {
        n = s1.size();
        if(s1 == s2) return 0;
        queue<string> q;
        q.push(s1);
        int level = 1;
        string s;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                s = q.front();
                q.pop();
                for(auto& next: neighbours(s, s2)){
                    if(next == s2) return level;
                    q.push(next);
                }
            }
            level++;
        }
        return -1;
    }
    vector<string> neighbours(string& s, string& s2){
        vector<string> ans;
        int i = 0;
        while(i<s2.size() and s[i]==s2[i])i++;
        for(int j = 0; j < n; j++){
            if(s[j] == s2[i]){
                char c = s[j];
                s[j] = s[i];
                s[i] = c;
                if(set.find(s) == set.end()){
                    ans.push_back(s);
                    set.insert(s);
                }
                s[i] = s[j]; s[j] = c;
            }
        }
        return ans;
    }
};