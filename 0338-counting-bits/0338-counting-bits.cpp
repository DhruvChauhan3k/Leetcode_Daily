class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int tmp=0;
            int ii=i;
            while(ii)
            {
                if(ii&1)tmp++;
                ii=ii>>1;
            }
            v[i]=tmp;
        }
        return v;
    }
};