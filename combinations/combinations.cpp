class Solution {
public:
void check(vector<vector<int>>&ans,vector<int>&temp,int i,int &n,int k)
{
        if(i==n+1 and k==0)
        {
            ans.push_back(temp);
             return;
        }
        if(i>n or k<0)return;
    
    check(ans,temp,i+1,n,k);
    temp.push_back(i);
    check(ans,temp,i+1,n,k-1);
    temp.pop_back();

}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        check(ans,temp,1,n,k);
        return ans;
    }
};