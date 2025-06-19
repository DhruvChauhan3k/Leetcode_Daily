bool comp(vector<int>&a,vector<int>&b){
    if(a[0]==b[0])return a[1]<b[1];
    return a[0]<b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0,n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int st=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(end>intervals[i][0])
            {
                ans++;
                if(end>intervals[i][1])
                {
                   st=intervals[i][0];
                   end=intervals[i][1];
                }
            }
            else
            {
                st=intervals[i][0];
                end=intervals[i][1];
            }
        }
        return ans;
    }
};