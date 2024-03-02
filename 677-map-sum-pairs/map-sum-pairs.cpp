class MapSum {
public:
unordered_map<string,int>m;
vector<string>uni;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(m.find(key)==m.end())
        {
            uni.push_back(key);
        }
        m[key]=val;
    }
    
    int sum(string x) {
        int ans=0;
        for(auto it:uni)
        {
           if(it.size()>=x.size())
           {
               string hk=it;
               string gh=hk.substr(0,x.size());
               if(gh==x)ans+=m[it];
           }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */