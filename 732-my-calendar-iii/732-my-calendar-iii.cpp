class MyCalendarThree {
    int maxx=0;
    map<int,int>m; 
public:
    MyCalendarThree() {
        
    }
    
    //line sweep
    int book(int start, int end) 
    {
        m[start]++;
        m[end]--;
        int c=0;
        for (auto it=m.begin();it!=m.end();it++) 
        {
            c+=it->second;
            maxx=max(c,maxx);
        }
        return maxx;   
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */