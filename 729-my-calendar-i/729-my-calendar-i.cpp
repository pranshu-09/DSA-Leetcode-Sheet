class MyCalendar {
public:
    
    map<int, int> ev;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = ev.upper_bound(start);
        
        if(next != ev.end() and (*next).second < end)
            return false;
        
        ev.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */