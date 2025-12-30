class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>s;
        for(int i=0;i<a.size();i++){
           if(!s.empty()){
            bool check=false;
             while(!s.empty()){
                 if((s.top()>=0 and a[i]<0)){
                    if(abs(s.top())<abs(a[i])){
                       s.pop();
                    }
                    else if(abs(s.top())==abs(a[i])){
                        s.pop();
                        check=true;
                    }
                    else{
                       check=true;
                    }
                 }
                 else{
                    s.push(a[i]);
                    check=true;
                 }
                 if(check)break;
             }
             if(!check)s.push(a[i]);
           }
           else{
            s.push(a[i]);
           }
        }

        vector<int>ans;
        while(!s.empty()){
            int x=s.top();
            ans.push_back(x);
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};