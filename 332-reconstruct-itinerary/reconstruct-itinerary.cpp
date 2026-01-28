class Solution {
public:
    void dfs(vector<string>& ans, unordered_map<string, multiset<string>>& adj, string u) {
        // Keep visiting neighbors as long as edges exist
        while(adj[u].size() > 0) {
            auto it = adj[u].begin();
            string v = *it;
            adj[u].erase(it); // Remove edge to prevent revisiting
            
            dfs(ans, adj, v);
        }
        
        // POST-ORDER: Add to list only after all children are visited
        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for(auto& t : tickets) {
            adj[t[0]].insert(t[1]);
        }
        
        vector<string> ans;
        dfs(ans, adj, "JFK");
        
        // Since we added elements in post-order (reverse), we must reverse it back
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};