#define ll long long
class Solution {
    static const int N=100100;
    int prime[N];
    int dp[N][2];
    //dp[i][0]-->tells the number of nodes before the previous prime traversed
    //dp[i][1]-->tells the number of nodes after the previous prime traversed
    ll res=0;
    //fooking TLE 921/922 passed
//     ll dfs(vector<int>g[],int n,int p,int start) {
//         if(n!=start&&dp.count(n))return 0;
//         ll tot=0;
    
//         for(int c:g[n]) {
//             if(c!=p) {
//                 ll val=dfs(g,c,n,start);
//                 if(n==start)res+=val+tot*val;
//                 tot+=val;
//             }
//         }
    
//         return tot+1;
//     }

    void dfs(vector<int>g[],int n,int p) {
        for(int c:g[n]) {
            if(c!=p) {
                dfs(g,c,n);
                if(prime[n])
                res+=dp[n][1]*dp[c][1];
                else {
                    res+=dp[n][1]*dp[c][0];
                    res+=dp[n][0]*dp[c][1];
                }
                
                
                if(prime[n])res+=dp[c][1];
                else res+=dp[c][0];
                // if(prime[n])res+=dp[n][1];
                dp[n][0]+=dp[c][0];
                dp[n][1]+=dp[c][1];
            }
        }
        
        dp[n][1]++;
        if(prime[n]) {
            dp[n][0]=dp[n][1];
            dp[n][1]=0;
        }
        // cout<<n<<" "<<dp[n][0]<<" "<<dp[n][1]<<" "<<res<<"\n";
    }
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        fill(prime,prime+N,1);
        prime[1]=0;
        for(int p=2;p*p<=n;p++) {
            if(prime[p]) {
                for(int i=p*p;i<=n;i+=p) {
                    prime[i]=0;
                }
            }
        }
        
        vector<int>g[n+1];
        for(auto e:edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        
        dfs(g,1,0);
        return res;
    }
};