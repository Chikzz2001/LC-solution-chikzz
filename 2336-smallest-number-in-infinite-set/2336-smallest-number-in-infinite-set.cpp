class SmallestInfiniteSet {
    set<int>S;
    int i=1;
public:
    SmallestInfiniteSet() 
    {
        
    }
    
    int popSmallest() 
    {
        if(S.size())
        {
            auto it=(S.begin());
            int res=*it;
            S.erase(it);
            return res;
        }
        else
        {i++;return i-1;}
    }
    
    void addBack(int num) 
    {
        if(num<i&&!S.count(num))
        S.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */