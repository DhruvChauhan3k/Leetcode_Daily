class Solution {
public:
    bool check(vector<int>temp,vector<vector<int>>&a)
    {
        for(int i=0;i<a.size();i++)
        {
            if(temp[i]==0)continue;
            for(int j=0;j<a[0].size();j++)
            {
                if(a[i][j]==1 and temp[j]==0)return  false;
                if(a[i][j]==0 and temp[j]==1)return false;
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& a) {
        vector<int>v(a.size(),0);
        int ans=0;
    for(int i=0;i<pow(2,a.size());i++)
    {
         int x=i;
         vector<int>temp=v;
         int j=0,cnt=0;
         while(x)
         {
             if(x&1)
             {
                cnt++;
                temp[j]=1;
             }
             j++;
             x=x>>1;
         }
         if(check(temp,a))
         {
             ans=max(ans,cnt);
         }
    }

     return ans;
    
    }
};