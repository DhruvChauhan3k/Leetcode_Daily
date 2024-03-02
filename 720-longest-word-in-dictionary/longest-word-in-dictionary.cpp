class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map<string,int>m;
        for(auto it:words)m[it]++;
        string india;
        int maxi=0;
        for(auto it:words)
        {
            // m[it]++;
            string temp;
            bool ans=true;
           for(auto x:it)
           {
               temp+=x;
               if(m.find(temp)==m.end())
               {
                   ans=false;
                   break;
               }
           }
           if(ans==true)
           {
               if(it.size()>maxi)
               {
                   maxi=it.size();
                   india=it;
               }
               else if(it.size()==maxi and it<india)
               {
                   india=it;
               }
           }
        }
        return india;
    }
};