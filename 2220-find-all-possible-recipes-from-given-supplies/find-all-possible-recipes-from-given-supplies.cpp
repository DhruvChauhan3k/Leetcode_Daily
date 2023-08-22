class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>m;
        unordered_map<string,int>n;
        for(int i=0;i<recipes.size();i++)
        {
            for(int j=0;j<ingredients[i].size();j++)
            {
                m[ingredients[i][j]].push_back(recipes[i]);
                n[recipes[i]]++;
            }
        }
        queue<string>q;
        for(auto it:supplies)
        {
            q.push(it);
            n[it]=0;
        }
        vector<string>ans;
        while(!q.empty())
        {
            string temp=q.front();
            q.pop();
            for(auto it:m[temp])
            {
                n[it]--;
                if(n[it]==0)
                {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};