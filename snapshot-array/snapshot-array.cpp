class SnapshotArray {
public:

    vector<map<int,int>>A;
    // snap_id
    int s_id = 0;

    SnapshotArray(int length) {
        
        // resizing the array to the given length
        A.resize(length);

        // intializing all the elements with 0;
        for(int i = 0; i < length; i++)
            A[i][0] = 0;
        
    }
    
    void set(int index, int val) {

      // setting value at the given index with current snap_id
        A[index][s_id] = val;
    }
    
    int snap() {
        s_id++;
        return  s_id - 1;
    }
    
    int get(int index, int id) {

    // checks if a given snap_id exists in a specific snapshot
    // (A[index]) and returns the value associated with that snap_id
    //  if found. If the snap_id is not present, it returns the 
    //  closest value that is less than the snap_id from the
    //  previous snapshots.

        while(id>=0 and A[index].find(id) == A[index].end())
        {
           id--;
        }
        if(id<0)return 0;
        return A[index][id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */