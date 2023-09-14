class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size();
        vector<int>l(n,1);
        vector<int>r=l;
        for(int i=1;i<n;i++)
        {
            if(rat[i]>rat[i-1])
            {
                l[i]=l[i-1]+1;
            }
        }
        for(int j=n-2;j>=0;j--)
        {
            if(rat[j]>rat[j+1])
            {
                r[j]=r[j+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=max(r[i],l[i]);
        }
        return ans;
    }
};