class Solution {
public:

     void dfs(int i,unordered_map<string,int>&visited,unordered_map<string,int>&supply,unordered_map<string,int>&res,vector<vector<string>>& ingredients,vector<string>&recipe){
        bool check=true;
        visited[recipe[i]]=0;
        for(auto it:ingredients[i]){
            if(supply.find(it)!=supply.end())continue;
            if(res.find(it)!=res.end()){
            if(visited.find(it)!=visited.end()){
                if(visited[it]==0){
                    check=false;
                }
            }
            else{
                dfs(res[it],visited,supply,res,ingredients,recipe);
                if(visited[it]==0)check=false;
            }
            }
            else{
                check=false;
            }
            if(check==false)break;
        }
        if(check)visited[recipe[i]]=1;
        else visited[recipe[i]]=0;
     }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int>supply,visited,res;
        for(auto it:supplies)supply[it]++;
        for(int i=0;i<recipes.size();i++)res[recipes[i]]=i;
        for(int i=0;i<recipes.size();i++){
            if(visited.find(recipes[i])==visited.end()){
                dfs(i,visited,supply,res,ingredients,recipes);
            }
        }
        vector<string>ans;
        for(auto it:visited){
            if(it.second==1)ans.push_back(it.first);
        }
        return ans;
    }
};