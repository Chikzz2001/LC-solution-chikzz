class Solution {
    class DSU
    {
        int *parent,*size;

        public:
        int res;
        DSU(int n)
        {
            parent=new int[n];
            size=new int[n];
            
            for(int i=0;i<n;i++)
                parent[i]=i;
            
            for(int i=0;i<n;i++)
                size[i]=1;
            
            res=n;
        }
        
        int find(int x)
        {
            if(parent[x]==x)
                return x;
            
            return parent[x]=find(parent[x]);
        }
        
        void join(int a,int b)
        {
            int pa=find(a);
            int pb=find(b);
            
            if(pa==pb)return;
            
            res--;
            if(size[pa]>=size[pb])
            {
                parent[pb]=pa;
                size[pa]+=size[pb];
            }
            else
            {
                parent[pa]=pb;
                size[pb]+=size[pa];
            } 
        }

    };
    
public:
    int removeStones(vector<vector<int>>& stones) 
    {    
        int n=stones.size();
        DSU dsu(n);
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]) 
                {
                    dsu.join(i,j);
                }
            }
        }
        return n-dsu.res>=0?n-dsu.res:0;
    }
};