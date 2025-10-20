class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto it:operations){
            int pos=0,neg=0;
            for(auto x:it){
                if(x=='-')neg++;
                if(x=='+')pos++;
            }
            if(neg>pos)ans--;
            else ans++;
        }
        return ans;
    }
};