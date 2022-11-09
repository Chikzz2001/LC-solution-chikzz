class StockSpanner {
    stack<pair<int,int>>stocks;
public:
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {
        int res=1;
        while(stocks.size()&&stocks.top().first<=price)
        {
            res+=stocks.top().second;
            stocks.pop();
        }
        stocks.push({price,res});
        return res;
    }
    //100  85
    //1    6
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */