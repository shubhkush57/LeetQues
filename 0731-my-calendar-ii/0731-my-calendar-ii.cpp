class MyCalendarTwo {
public:
    #define pp pair<int,int>
    set<pp>st;
    set<pp>dt;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it: dt){
            int sp = it.first;
            int ep = it.second;
            if(sp<=start){
                if(start<ep){
                    return false;
                }
            }
            else{
                if(sp<end){
                    return false;
                }
            }
        }
        // see if intersect with the st..
        bool flag = true;
        for(auto& it: st){
            int sp = it.first;
            int ep = it.second;
            if(sp<=start){
                if(start<ep){
                    // yes intersection..
                    dt.insert({start,min(end,ep)});
                    // return false;
                }
            }
            else{
                if(sp<end){
                    // return false;
                    dt.insert({sp,min(end,ep)});
                }
            }
        }
       
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */