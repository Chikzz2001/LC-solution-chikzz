class LockingTree {
    vector<int>locked;
    vector<vector<int>>tree;
    vector<int>par;
    bool check_for_ancestors(int num)
    {
        while(num!=-1)
        {
            if(locked[num])return 0;
            num=par[num];
        }
        return 1;
    }
    bool check_for_descendants(int num,int node,int p)
    {
        if(num!=node&&locked[node])
            return 1;
        for(auto &nbr:tree[node])
        {
            if(nbr!=p)
            {
                if(check_for_descendants(num,nbr,node))
                    return 1;
            }
        }
        return 0;
    }
    void unlock_all_descendants(int node,int p)
    {
        for(auto &nbr:tree[node])
        {
            if(nbr!=p)
            {
                locked[nbr]=0;
                unlock_all_descendants(nbr,node);
            }
        }
    }
public:
    LockingTree(vector<int>& parent) {
        int n=parent.size();
        locked=vector<int>(n,0);
        par=parent;
        tree=vector<vector<int>>(n);
        for(int i=0;i<n;i++)
        {
            if(parent[i]!=-1)
            {
                tree[parent[i]].push_back(i);
                tree[i].push_back(parent[i]);
            }
        }
    }
    
    bool lock(int num, int user) {
        if(locked[num])return 0;
        locked[num]=user;
        return 1;
    }
    
    bool unlock(int num, int user) {
        if(locked[num]!=user)
            return 0;
        locked[num]=0;
        return 1;
    }
    
    bool upgrade(int num, int user) {
        if(locked[num])return 0;
        bool f1=check_for_ancestors(num);
        bool f2=check_for_descendants(num,num,par[num]);
        if(f1&f2)
        {locked[num]=user;unlock_all_descendants(num,par[num]);return 1;}
        return 0;
        
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */