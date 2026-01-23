class Solution {
public:
vector<int>now;
int size=0;
    Solution(vector<int>& w) {
        now=w;
        for(int i=1;i<w.size();i++){
            now[i]+=now[i-1];
        }
        size=now[w.size()-1];
    }
    
    int pickIndex() {
        int ran=(rand()%size)+1;
        int x=lower_bound(now.begin(),now.end(),ran)-now.begin();
        return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */