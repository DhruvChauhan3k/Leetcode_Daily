class SnapshotArray {
public:
    // Outer vector = indices (0 to length-1)
    // Inner vector = History of changes for that index: {snap_id, value}
    vector<vector<pair<int, int>>> history;
    int curSnapId = 0;

    SnapshotArray(int length) {
        history.resize(length);
    }
    
    void set(int index, int val) {
            history[index].push_back({curSnapId, val});
    }
    
    int snap() {
        return curSnapId++;
    }
    
    int get(int index, int snap_id) {

        auto it = upper_bound(history[index].begin(), 
                              history[index].end(), 
                              make_pair(snap_id, INT_MAX));
        if(it==history[index].begin())return 0;
        
        return prev(it)->second;
    }
};