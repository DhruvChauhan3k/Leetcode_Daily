class TimeMap {
public:
    unordered_map<string,map<int,string>>m;
    TimeMap() {
        return;
    }
    void set(string key, string value, int time) {
     m[key][time]=value;   
    }
    
    string get(string key, int time) {
        auto it = m[key].upper_bound(time);
      return it == m[key].begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */