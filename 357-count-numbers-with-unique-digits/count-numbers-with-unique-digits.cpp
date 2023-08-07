class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1)return 10;
        int final=10;
        for(int k=2;k<=n;k++)
        {
            int ans=9;
            int prev=9;
            for(int o=1;o<k;o++)
            {
                ans=ans*prev;
                prev--;
            }
            final+=ans;
        }
        return final;
    }
};