class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>m;
        for(auto it:emails){
            string temp;
            bool plus=false;
            bool rate=false;
            for(auto x:it){
                if(x=='@')rate=true;
                if(x=='+')plus=true;
                if(rate)temp+=x;
                else if(plus||x=='.')continue;
                else{
                        temp+=x;
                }
            }
            m[temp]++;
        }
        return m.size();
    }
};