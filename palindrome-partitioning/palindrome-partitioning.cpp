class Solution {
public:
    bool pal(string&s)
    {
        int st=0,e=s.size()-1;
        while(st<e)
        { 
            if(s[st]!=s[e])
            {
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
    void check(int i,string &s, vector<vector<string>>&ans,vector<string>temp,string st)
    {
        if(i==s.size())
        {
            if(st.size()>0 and pal(st))
            {
                temp.push_back(st);
                ans.push_back(temp);
            }
            return;
        }
        st+=s[i];
        check(i+1,s,ans,temp,st);
        if(pal(st))
        {
            temp.push_back(st);
            check(i+1,s,ans,temp,"");
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        string st;
        check(0,s,ans,temp,st);
        return ans;
    }
};