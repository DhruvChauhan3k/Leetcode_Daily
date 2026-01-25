class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        // We need to bundle the data together so we can sort them based on indices
        // Tuple: {index, source, target}
        vector<tuple<int, string, string>> operations;
        
        for(int i = 0; i < indices.size(); i++) {
            operations.push_back({indices[i], sources[i], targets[i]});
        }
        
        // Sort in DESCENDING order (Reverse Sorted)
        // We use a lambda comparator or rbegin/rend
        sort(operations.rbegin(), operations.rend());
        
        for(auto& op : operations) {
            int idx = get<0>(op);
            string src = get<1>(op);
            string tgt = get<2>(op);
            
            // Check if the substring matches the source
            // Be careful to check bounds (though usually guaranteed valid start index)
            if(idx + src.size() <= s.size() && s.substr(idx, src.size()) == src) {
                // Replace: s.replace(pos, len, string_to_put)
                s.replace(idx, src.size(), tgt);
            }
        }
        
        return s;
    }
};