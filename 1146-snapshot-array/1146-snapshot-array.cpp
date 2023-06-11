class SnapshotArray {
public:
    #define pp pair<int,int>
    vector<vector<pp>>v;
    int call = 0;
    SnapshotArray(int length) {
        v.resize(length);
        for(int i = 0;i<length;i++){
            v[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        v[index].push_back({call,val});
        return;
    }
    
    int snap() {
        call++;
        return call-1;
    }
    
    int get(int index, int snap_id) {
        //here the binary serach for search ing th id...
        auto it = upper_bound(v[index].begin(), v[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */