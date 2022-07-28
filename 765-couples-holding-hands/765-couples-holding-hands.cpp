class Solution {
    class DSU
    {
        public:
        vector<int>par,size;
        DSU(int n)
        {
            par=vector<int>(n);
            size=vector<int>(n,1);
            for(int i=0;i<n;i++)
                par[i]=i;
        }
        
        int find(int x)
        {
            if(par[x]==x)return x;
            return par[x]=find(par[x]);
        }
        
        bool is_joined(int a,int b)
        {
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)return 1;
            
            if(size[pa]>size[pb])
            {
                par[pb]=pa;
                size[pa]+=size[pb];
            }
            else
            {
                par[pa]=pb;
                size[pb]+=size[pa];
            }
            return 0;
        }
    };
public:
    int minSwapsCouples(vector<int>& row) 
    {
        int n=row.size();
        
        DSU dsu(n/2);
        for(int i=0;i<n;i+=2)
        {
            dsu.is_joined(row[i]/2,row[i+1]/2);
        }
        
        int res=0;
        set<int>parents;
        for(int i=0;i<n;i++)
        {
            parents.insert(dsu.find(row[i]/2));
        }
        
        for(auto &p:parents)
            res+=dsu.size[p]-1;
        return res;
    }
};

//2 0 0 1 1 2
//0 0 1 1 2 2
        
//[5,6,3,7,1,0,2,4]
// 2 3 1 3 0 0 1 2
// 0 0 1 1 2 2 3 3
        
//[5,6,9,7,1,2,0,4,8,3]
// 2 3 4 3 0 0 1 2 4 1
        
//2-3-4-1-0
//0 2 1 3

//6,7 8,9 10,1 2,4 3,5 