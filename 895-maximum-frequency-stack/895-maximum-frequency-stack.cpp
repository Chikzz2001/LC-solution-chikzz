class FreqStack {
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>bucket;
    int maxfreq = 0;

public:
    FreqStack() 
    {
        
    }

    void push(int x) 
    {
        //we update the current maxfrequency of any ele present in the stack so far
        maxfreq = max(maxfreq,++freq[x]);
        //we push the ele in the freq in which it currently belongs 
        bucket[freq[x]].push(x);
    }

    int pop() 
    {
        //the popped ele will obviously be the top ele of the stack corresponding to maxfreq
        int res=bucket[maxfreq].top();
        bucket[maxfreq].pop();
        
        //if no more ele is present on successive popping from the freq[res]/maxfreq--->stack
        //then we decrement the maxfreq
        if(!bucket[freq[res]--].size()) 
            maxfreq--;
        
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */