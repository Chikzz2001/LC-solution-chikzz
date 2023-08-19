class StockPrice {
    map<int,int>m;
    map<int,int>freq;
    int maxx=0,minn=1e9,curr=0;
    int T=0;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(m.count(timestamp)) {
            freq[m[timestamp]]--;
            if(freq[m[timestamp]]==0)freq.erase(m[timestamp]);
        }

        freq[price]++;
        m[timestamp]=price;
        
        minn=(freq.begin())->first;
        auto it=freq.end();
        it--;
        maxx=it->first;
        
        it=m.end();
        it--;
        curr=it->second;
    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        return maxx;
    }
    
    int minimum() {
        return minn;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */