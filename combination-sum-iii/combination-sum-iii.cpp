class Solution {
public:
void check(vector<vector<int>>&ans,vector<int>&temp,int k,int n,int i)
{
    if(n==0 and k==0)
    {
        ans.push_back(temp);
        return;
    }
    if(i>9 or n<=0 or k<=0)return;
    check(ans,temp,k,n,i+1);
    temp.push_back(i);
    check(ans,temp,k-1,n-i,i+1);
    temp.pop_back();
}
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>>ans;
      vector<int>temp;
      check(ans,temp,k,n,1);  
      return ans;
    }
};