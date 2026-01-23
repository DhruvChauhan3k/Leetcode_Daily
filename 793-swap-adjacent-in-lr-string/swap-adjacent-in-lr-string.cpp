class Solution {
public:
    bool canTransform(string start, string result) {
        int cntR=0, cntL=0;
        int n = start.size();
        for(int i=0;i<n;i++){
            if(start[i]=='R') cntR++;
            if(result[i]=='R'){
                if(cntL || cntR==0) return 0;
                cntR--;
            }
            if(result[i]=='L') cntL++;
            if(start[i]=='L'){
                if(cntR || cntL==0) return 0;
                cntL--;
            }
        }
        return cntR==0 && cntL==0;
    }
};