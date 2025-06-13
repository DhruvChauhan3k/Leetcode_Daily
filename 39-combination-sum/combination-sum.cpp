class Solution {
public:
void check(vector<vector<int>>&ans,vector<int>&temp,int i,vector<int>& c, int t)
{
    if(i==c.size() or t<0)return;
    if(t==0)
    {
        ans.push_back(temp);
        return;
    }
    check(ans,temp,i+1,c,t);
    temp.push_back(c[i]);
    check(ans,temp,i,c,t-c[i]);
    temp.pop_back();

}
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
       vector<vector<int>>ans;
       vector<int>temp;
       check(ans,temp,0,c,t);
       return ans; 
    }
};