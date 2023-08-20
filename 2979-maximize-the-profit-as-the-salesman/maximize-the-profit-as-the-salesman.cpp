class Solution {
public:
    
    vector<int> memo;
    
    // next non-conflicting house range index that can be sold
    int search(vector<vector<int>>& offers, int end, int idx){
        int n=offers.size();
        int l=idx, r=n-1;
        int i=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int start=offers[m][0];
            if(start>end){
                i=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return i;
    }
    
    int getProfit(vector<vector<int>>& offers, int n, int idx){
        if(idx == n) return 0;
        
        if(memo[idx]!=-1) return memo[idx];
        
        // not sell
        int maxGold = getProfit(offers, n, idx+1);
        
        // sell
        int next_possible_idx = search(offers, offers[idx][1], idx+1);
        maxGold = max(maxGold, offers[idx][2] + (next_possible_idx==-1 ? 0:getProfit(offers,n,next_possible_idx)));
        
        return memo[idx]=maxGold;
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        
        int m=offers.size();
        memo.resize(m,-1);
        
        return getProfit(offers,m,0);
    }
};