class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.length();
        stack<int>l,r;
        vector<int>left(n,-1);
        vector<int>right(n,n);
        vector<int>sum(n,0);
        int last=-1;
        int i=0;
        int prev=0;
        for(auto it:s){
            if(it=='|'){
                last=i;
                 prev++;
            }
            sum[i]=prev;
            left[i]=last;
            i++;
        }
        last=n;
        for(i=n-1;i>=0;i--){
            if(s[i]=='|')last=i;
            right[i]=last;
        }
        vector<int>ans;
        for(auto it:queries){
            if(left[it[1]]-right[it[0]]-1<0)ans.push_back(0);
            else ans.push_back(left[it[1]]-right[it[0]]-1-(sum[left[it[1]]]-sum[right[it[0]]]-1));
        }
        return ans;
    }
};