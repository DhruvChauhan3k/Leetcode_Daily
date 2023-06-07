class Solution {
public:
void check(vector<int>&a,int x)
{
    int i=0;
    while(x>0)
    {
        a[i]=x&1;
        i++;
        x=x>>1;
    }
}
    int minFlips(int a, int b, int c) {

        vector<int>a1(32,0);
        vector<int>b1(32,0);
        vector<int>c1(32,0);
        check(a1,a);
        check(b1,b);
        check(c1,c);
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(c1[i]==1)
            {
                if(a1[i]==0 and b1[i]==0)ans++;
            }
            else
            {
                if(a1[i]==1 and b1[i]==1)ans+=2;
                else if(a1[i]==1 or b1[i]==1) ans++;
            }
        }
        return ans;
    }
};