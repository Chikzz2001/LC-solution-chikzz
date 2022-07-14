class CustomStack {
    vector<int>add;
    stack<int>st;
    int N;
public:
    CustomStack(int maxSize) 
    {
        N=maxSize;
        add.resize(maxSize,0);
    }
    
    void push(int x) 
    {
        if(st.size()<N)
            st.push(x);
    }
    
    int pop() 
    {
        if(!st.size())return -1;
        int res=st.top();st.pop();
        int size=st.size();
        int val=add[size];
        add[size]=0;
        if(size-1>=0)add[size-1]+=val;
        return res+val;
    }
    
    void increment(int k, int val) 
    {
        int size=st.size();
        if(!size)return;
        add[min(k,size)-1]+=val;
    }
};

/*

30 
0 100 100


*/



/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */