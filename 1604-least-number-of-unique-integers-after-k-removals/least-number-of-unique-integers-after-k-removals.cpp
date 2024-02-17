    unordered_map<int,int>m;  
    bool comp(int &a,int &b)
    {
        return m[a]<m[b]; 
    }

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        m.clear();
        vector<int>uni;
        for(auto it:arr)
        {
            if(m.find(it)==m.end())uni.push_back(it);
                m[it]++;
        }
        sort(uni.begin(),uni.end(),comp);
        int st=0;
        while(st<uni.size())
        {
            if(m[uni[st]]>k)break;
            k-=m[uni[st]];
            st++;
        }
        return uni.size()-st;
    }
};