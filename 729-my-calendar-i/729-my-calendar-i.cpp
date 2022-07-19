class MyCalendar {
    vector<vector<int>>events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        if(!events.size())
        {
            events.push_back({start,end});
            return 1;
        }
        int lo=0,hi=events.size()-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(events[mid][0]>=start)
                hi=mid-1;
            else
                lo=mid+1;
        }
        lo--;
        if(lo==-1)
        {
            if(events[0][0]>=end)
            {
                events.insert(events.begin(),{start,end});
                return 1;
            }
        }
        if(lo>=0&&events[lo][1]<=start)
        {
            if(lo+1<events.size())
            {
                if(events[lo+1][0]>=end)
                {
                    // events.push_back({start,end});
                    // sort(events.begin(),events.end());
                     events.insert(events.begin()+(lo+1),{start,end});
                    return 1;
                }
                return 0;
            }
            events.push_back({start,end});
            // sort(events.begin(),events.end());
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */