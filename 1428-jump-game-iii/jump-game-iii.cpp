class Solution {
public:
    bool check(vector<int>&arr,int start,vector<int>&visit)
    {
        visit[start]=1;
        if(arr[start]==0)return true;
        int a=start+arr[start],b=start-arr[start];
        if(a<arr.size() and visit[a]==0)
        {
            if(check(arr,a,visit))return true;
        }
        if(b>=0 and visit[b]==0)
        {
            if(check(arr,b,visit))return true;
        }
        visit[start]=0;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>visit(arr.size(),0);
        return check(arr,start,visit);
    }
};