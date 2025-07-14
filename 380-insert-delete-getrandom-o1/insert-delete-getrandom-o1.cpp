#define pb push_back
class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mymap;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mymap.find(val)!=mymap.end())
            return false;
        
        v.pb(val);
        mymap[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        if(mymap.find(val)==mymap.end())
            return false;
        
        int it = mymap[val];
        swap(v[v.size()-1],v[it]);
        v.pop_back();
        mymap[v[it]] = it;
        mymap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
