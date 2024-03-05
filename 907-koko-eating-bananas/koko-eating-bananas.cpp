class Solution {
public:
     long long int check(int x,vector<int>&piles)
     {
         long long int time=0;
         for(auto it:piles)
         {
            time+=it/x;
            if(it%x!=0)time++;
         }
         return time;
     }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=0;
        for(auto it:piles)e=max(e,it);
        int ans=1e9;
        while(s<=e)
        {
             int mid=(s+e)/2;
             long long int a=check(mid,piles);
             if(a<=h)
             {
                 ans=min(ans,mid);
                 e=mid-1;
             }
             else
             {
                 s=mid+1;
             }
        }
        return ans;
    }
};