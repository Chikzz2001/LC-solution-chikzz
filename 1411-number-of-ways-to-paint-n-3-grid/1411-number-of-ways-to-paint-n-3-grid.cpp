class Solution {
    vector<vector<int>>g;
    vector<int>t;
    vector<vector<int>>dp;
    const int M=1e9+7;
    
    void generate(int n) {
        if(t.size()==n) {
            g.push_back(t);
            return;
        }
        
        for(int i=0;i<=2;i++) {
            if(!t.size()||t.back()!=i) {
                t.push_back(i);
                generate(n);
                t.pop_back();
            }
        }
    }
    
    int helper(int i,int m,int pre) {
        if(i==m)return 1;
        
        if(dp[i][pre]!=-1)return dp[i][pre];
        
        int res=0;
        for(int j=0;j<g.size();j++) {
            bool match=1;
            for(int k=0;k<g[j].size();k++) {
                if(g[pre][k]==g[j][k]){match=0;break;}
            }
            if(match) {
                res=(res%M+helper(i+1,m,j)%M)%M;
            }
        }
        return dp[i][pre]=res;
    }
public:
    int numOfWays(int m) {
        generate(3);
        
        int sz=g.size();
        dp=vector<vector<int>>(m,vector<int>(sz,-1));
        int res=0;
        for(int i=0;i<sz;i++) {
            res=(res%M+helper(1,m,i)%M)%M;
        }
        return res;
    }
};