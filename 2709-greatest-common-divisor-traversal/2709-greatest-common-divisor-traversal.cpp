class Solution {
    int find(int x,map<int,int>& p) {
        if(p[x]==x)return x;
        return p[x]=find(p[x],p);
    }
    void join(int a,int b,map<int,int>& p) {
        int pa=find(a,p);
        int pb=find(b,p);
        p[pa]=pb;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
         int n=nums.size();
        if(n==1)return 1;
        
        int maxx=*max_element(nums.begin(),nums.end());
        map<int,int>par;
        for(int x:nums) {
            if(x==1)return 0;
            par[x]=x;
        }
        
        
        vector<bool>prime(maxx+1,1);
        for(int i=2;i<=maxx;i++) {
            if(!prime[i])continue;
            par[i]=i;
            for(int j=2*i;j<=maxx;j+=i) {
                if(par.count(j)) {
                    if(par[j]==j)par[j]=i;
                    else {
                        int p=find(j,par);
                        join(p,i,par);
                    }
                }
                prime[j]=0;
            }
        }
       
        set<int>parent;
        for(int x:nums) {
            parent.insert(find(x,par));
        }
        
        return parent.size()==1;
    }
};