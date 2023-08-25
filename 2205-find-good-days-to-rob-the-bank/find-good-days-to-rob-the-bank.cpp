class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int n=s.size();
        vector<int>left(n,0),right(n,0);
        for(int i=1;i<n;i++)
        {
            if(s[i]<=s[i-1])left[i]=1+left[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]<=s[i+1])right[i]=right[i+1]+1;
        }
        vector<int>ans;
        for(int i=time;i<n-time;i++)
        {
            if(left[i]>=time and right[i]>=time)ans.push_back(i);
        }
        return ans;
    }
};