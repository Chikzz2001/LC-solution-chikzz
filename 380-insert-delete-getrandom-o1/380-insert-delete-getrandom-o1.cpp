class RandomizedSet {
    //val-->index of store at which val is present
    map<int,int>val_idx;
    vector<int>store;
    int size=0;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(val_idx.count(val))return 0;
        store.push_back(val);
        val_idx[val]=size;
        size++;
        return 1;
    }
    
    bool remove(int val) {
        if(!val_idx.count(val))return 0;
        int idx=val_idx[val];
        store[idx]=store[size-1];
        val_idx[store[size-1]]=idx;
        val_idx.erase(val);
        store.pop_back();
        size--;
        return 1;
    }
    
    int getRandom() {
        int idx=rand()%size;
        return store[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */