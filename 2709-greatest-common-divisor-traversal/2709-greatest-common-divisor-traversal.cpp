class Solution {
    class DSU {
        public:
        vector<int>par,size;
        DSU(int n) {
            par=vector<int>(n);
            size=vector<int>(n,1);
            for(int i=0;i<n;i++)par[i]=i;
        }
        int find(int x) {
            if(x==par[x])return x;
            return par[x]=find(par[x]);
        }
        void join(int a,int b) {
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)return;
            if(size[pa]<size[pb]) {
                par[pa]=par[pb];
                size[pb]+=size[pa];
            }
            else {
                par[pb]=par[pa];
                size[pa]+=size[pb];
            }
        }
    };
public:
    bool canTraverseAllPairs(vector<int>& nums) {
         int n=nums.size();
        if(n==1)return 1;
        int maxx=*max_element(nums.begin(),nums.end());
       
        DSU dsu(n);
        map<int,int>id;
        for(int i=0;i<n;i++) {
            if(nums[i]==1)return 0;
            for(int j=2;j*j<=nums[i];j++) {
                if(nums[i]%j==0) {
                    if(id.count(j)) {
                        dsu.join(id[j],i);
                    }
                    else {
                        id[j]=i;
                    }
                    while(nums[i]%j==0) {
                        nums[i]/=j;
                    }
                }
            }
            if(nums[i]>1) {
                if(id.count(nums[i])) {
                    dsu.join(id[nums[i]],i);
                }
                else {
                    id[nums[i]]=i;
                }
            }
        }
        return dsu.size[dsu.find(0)]==n;
    }
};