class Solution {
public:
    bool check(vector<int>&arr,int start,vector<int>&visit,vector<int>&dp)
    {
        if(dp[start]!=-1)return dp[start];
        visit[start]=1;
        if(arr[start]==0)return true;
        int a=start+arr[start],b=start-arr[start];
        bool ak=false;
        if(a<arr.size() and visit[a]==0)
        {
            if(check(arr,a,visit,dp))ak=true;
        }
        if(b>=0 and visit[b]==0)
        {
            if(check(arr,b,visit,dp))ak= true;
        }
        visit[start]=0;
        return dp[start]=ak;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>visit(arr.size(),0);
        vector<int>dp(arr.size(),-1);
        return check(arr,start,visit,dp);
    }
};