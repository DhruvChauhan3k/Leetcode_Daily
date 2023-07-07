class Solution {
public:
    bool check(int i,vector<vector<int>>& graph, vector<int>&color)
    {
        for(auto it:graph[i])
        {
             if(color[it]!=0 and color[it]==color[i])return false;
             if(color[it]==0)
             {
                 color[it]=-1*color[i];
                 if(check(it,graph,color)==false)return false;
             }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==0)
            {
                color[i]=1;
                if(check(i,graph,color)==false)return false;
            }
        }
        return true; 
    }
};