class Solution {
public:
    long long waysToBuyPensPencils(int t, int c1, int c2) {
        if(c1<c2)swap(c1,c2);
        long long int ans=0;
        long long int take=t/c1;
        for(int i=0;i<=take;i++)
        {
            long long int now=t-i*c1;
            ans++;
            ans+=(now/c2);
        }
        return ans;
    }
};