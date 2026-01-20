class Solution {
public:
    void dfs(vector<string>&ans,unordered_map<string,multiset<string>>&adj,string begin)
    {
        if(adj[begin].size()==0)
        {
            ans.push_back(begin);
            return;
            // st.pop();
        }
        else
        {
            while(adj[begin].size())
            {
                auto it=adj[begin].begin();
                string n=*it;
                adj[begin].erase(it);
                dfs(ans,adj,n);
            }
        }
        ans.push_back(begin);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       unordered_map<string,multiset<string>>adj;
       for(auto it:tickets)
       {
           adj[it[0]].insert(it[1]);
       }
    //    stack<string>st;
       vector<string>ans;
       dfs(ans,adj,"JFK");
       reverse(ans.begin(),ans.end());
       return ans;
    }
};