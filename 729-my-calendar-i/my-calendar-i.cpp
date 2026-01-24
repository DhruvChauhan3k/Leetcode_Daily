class MyCalendar {
public:
vector<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto it:v){


            if((startTime<it.first and endTime<=it.first) || (endTime>=it.second and startTime>=it.second))continue;
            return false;
        }
        v.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */