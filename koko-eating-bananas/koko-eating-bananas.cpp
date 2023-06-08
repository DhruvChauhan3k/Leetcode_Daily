class Solution {
public:
    bool check(int x,vector<int>piles,int h)
    {
        double now=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%x==0)now+=piles[i]/x;
            else now+=piles[i]/x+1;
        }
        if(now>h)return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int hi) {
        int l=1,h=1;
        for(int i=0;i<piles.size();i++)h=max(piles[i],h);
        int ans=1e9;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(check(mid,piles,hi))
            {
                ans=min(ans,mid);
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};