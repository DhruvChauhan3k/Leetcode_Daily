class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        unordered_map<int,int>m;
        if(hand.size()%gs!=0)return false; 
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:hand){
            if(m.find(it)==m.end())pq.push(it);
            m[it]++;
        }
        while(pq.size()>=gs){
            vector<int>q;
            int x=pq.top();
            pq.pop();
            if(m[x]>1){
                m[x]--;
                q.push_back(x);
            }
            for(int i=1;i<gs;i++){
                if(pq.top()==1+x){
                   x=pq.top();
                   pq.pop();
                   if(m[x]>1){
                    m[x]--;
                    q.push_back(x);
                   }
                }
                else{
                    return false;
                }
            }
            for(auto x:q)pq.push(x);
            if(pq.empty())return true;
        }
        return false;
    }
};