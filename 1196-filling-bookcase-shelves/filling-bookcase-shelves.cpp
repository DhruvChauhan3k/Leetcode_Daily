class Solution {
public:
    int ansCalc(vector<vector<int>>&books,vector<int>&dp,int i,int sw){
        if(i>=books.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int now=0;
        int ans=1e9;
        int maxh=0;
        int j=i;
        while(i<books.size() and now+books[i][0]<=sw){
            now+=books[i][0];
            maxh=max(maxh,books[i][1]);
            ans=min(ans,maxh+ansCalc(books,dp,i+1,sw));
            i++;
        }
        return dp[j]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        vector<int>dp(books.size(),-1);
        return ansCalc(books,dp,0,sw);
    }
};