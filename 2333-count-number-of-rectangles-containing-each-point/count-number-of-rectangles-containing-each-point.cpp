class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& point) {
        vector<vector<int>>check(101);
        for(auto it:rec)
        {
            check[it[1]].push_back(it[0]);
        }
        for(int i=1;i<101;i++)
        {
            sort(check[i].begin(),check[i].end());
        }
        vector<int>ans;
        for(auto it:point)
        {
              int l=it[0],h=it[1];
              int curr=0;
              for(int k=h;k<101;k++)
              {
                  curr+=(check[k].end()-lower_bound(check[k].begin(),check[k].end(),l));
              }
              ans.push_back(curr);
        }
        return ans;
    }
};