#define ff first
#define ss second

class Solution {
    pair<int,bool> dfs(vector<int>g[],int n,int p,int val,vector<int>& nums) {
        int s=nums[n];
        for(int c:g[n]) {
            if(c!=p) {
                auto P=dfs(g,c,n,val,nums);
                if(!P.ss)return {0,0};
                else {
                    s+=P.ff;
                }
            }
        }
        if(s<val)return {s,1};
        else if(s==val)return {0,1};
        else return {0,0};
    }
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<int>g[n];
        
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        int s=accumulate(nums.begin(),nums.end(),0);
        
        //max number of edge del=max components
        int maxx=0;
        //1<=s/i<=n
        for(int i=1;i<=sqrt(s);i++) {
            if(s%i==0) {
                //s/i-->components i-->val
                if(s/i<=n&&dfs(g,0,-1,i,nums).ss)return s/i-1;
                if(i<=n&&dfs(g,0,-1,s/i,nums).ss)maxx=max(maxx,i-1);
            }
        }
        return maxx;
    }
};