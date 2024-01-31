class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>v(n,0);
        stack<pair<int,int>>s;
        s.push({t[0],0});
        for(int i=1;i<n;i++)
        { 
             while(!s.empty() and s.top().first<t[i])
             {
                 v[s.top().second]=i-s.top().second;
                 s.pop();
             }
             s.push({t[i],i});
        }
        return v;
    }
};