class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>m;
        int cnt=0;
        for(auto it:s){
            m[it].push_back(cnt);
            cnt++;
        }
        int ans=0;
        for(auto it:words){
            int check=true;
            int start=-1;
            for(auto x:it){
                if(m.find(x)!=m.end()){
                    int now=upper_bound(m[x].begin(),m[x].end(),start)-m[x].begin();
                    if(now>=m[x].size()){
                        check=false;
                        break;
                    }
                    else{
                        start=m[x][now];
                    }
                }
                else{
                    check=false;
                    break;
                }
            }
            if(check)ans++;
        }
        return ans;
    }
};