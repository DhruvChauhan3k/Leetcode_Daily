class Solution {
public:
int check(int i,int prev,vector<int>&nums,vector<vector<int>>&dp)
{
    if(i==nums.size())return 0;
    if(dp[i][prev]!=-1)return dp[i][prev];
    if(prev==0)
    {
        return dp[i][prev]= max(1+check(i+1,i+1,nums,dp),check(i+1,prev,nums,dp));
    }
    if(nums[i]%nums[prev-1]==0)
    {
        return dp[i][prev]= max(1+check(i+1,i+1,nums,dp),check(i+1,prev,nums,dp));
    }
    return dp[i][prev]= check(i+1,prev,nums,dp);
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        // int s=0,e=0;
        // vector<int>ans;
        // while(s<n and e<n)
        // {
        //      if( ((s==n-1 or e==n-1) and dp[s][e]==ni) or  (s!=n-1 and e!=n-1 and ni==1+dp[s+1][s+1]))
        //      {
        //          ans.push_back(nums[s]);
        //          e=s+1;
        //          s=s+1;
        //          ni--;
        //      }
        //      else
        //      {
        //         //  ni--;
        //           s++;
        //      }
        // }
        vector<vector<int>>fin(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i;prev>=0;prev--)
            {
                    if(prev==0)
                    {
                       dp[i][prev]= max(1+dp[i+1][i+1],dp[i+1][prev]);
                       if(dp[i][prev]==1+dp[i+1][i+1])
                       {
                           fin[i][prev]=i+1;
                       }
                       else
                       {
                           fin[i][prev]=prev;
                       }
                    }
                    else if(nums[i]%nums[prev-1]==0)
                    {
                       dp[i][prev]= max(1+dp[i+1][i+1],dp[i+1][prev]);
                       if(dp[i][prev]==1+dp[i+1][i+1])
                       {
                           fin[i][prev]=i+1;
                       }
                       else
                       {
                           fin[i][prev]=prev;
                       }
                    }
                    else
                    {
                       dp[i][prev]= dp[i+1][prev];
                       fin[i][prev]=prev;
                    }
            }
        }
        vector<int>ck;
        int prev=0,i=0;
        while(i<n and prev<n)
        {
            if(fin[i][prev]==prev)
            {
                i++;
            }
            else
            {
                prev=fin[i][prev];
                i++;
                ck.push_back(nums[i-1]);
            }
        }
         
        //  int ni= dp[0][0];
        // vector<int>ans(ni,-1);


        return ck;
    }
};