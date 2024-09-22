class Solution {
public:
    bool check(int x,vector<int>&p,int h)
    {
       long long int cnt=0,n=p.size(),i=0;
       while(i<n)
       {
        if(p[i]>x)
        {
            if(p[i]%x!=0)cnt++;
           cnt+=((p[i])/x);
        }
        else cnt++;
        i++;
       }
       return cnt<=h;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int s=1,e=0;
        sort(p.begin(),p.end());
        for(auto it:p)e=max(e,it);
        int ans=1e9;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(check(mid,p,h))
            {
                e=mid-1;
                ans=min(ans,mid);
            }
            else s=mid+1;
        }
        return ans;
    }
};