class Solution {
public:
    double check(double x,long long int n)
    {
        if(n==0)return 1.0;
        // if(dp[x][n]!=-1)return dp[x][n];
        if(n%2==0)
        {
            double c=check(x,n/2);
            return c*c;
        }
        else
        {
            return x*check(x,n-1);
        }
        return 0.0;
    }
    double myPow(double x, int n) {
        if(x>=0)
        {
               if(n>=0)
               {
                    //  vector<vector<double>>dp(x+1,vector<double>(n+1,-1));
                     return check(x,n);
               }
               else
               {
                   n=abs(n);
                    //    vector<vector<double>>dp(x+1,vector<double>(n+1,-1));
                       return 1.0/check(x,n);
               }
        }
        else
        {
            x=abs(x);
            if(n>=0)
            {
                 if(n%2==0)
                 {
                    //  vector<vector<double>>dp(x+1,vector<double>(n+1,-1));
                     return check(x,n);
                 }
                 else
                 {
                    //  vector<vector<double>>dp(x+1,vector<double>(n+1,-1));
                     return -1.0*check(x,n);
                 }
            }
            else
            {
                n=abs(n);
                if(n%2==0)
                 {
                    //  vector<vector<double>>dp(x+1,vector<double>(n+1,-1));
                     return 1.0/check(x,n);
                 }
                 else
                 {
                    //  vector<vector<double>>dp(x+1,vector<double>(n+1,-1));
                     return 1.0/(-1.0*check(x,n));
                 }
                  
            }

        }
        return 0.0;
    }
};