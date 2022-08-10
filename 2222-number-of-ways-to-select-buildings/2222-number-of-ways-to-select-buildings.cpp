#define ll long long int
class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.length();
        vector<vector<int>>prev(n+2,vector<int>(2,0));
        vector<vector<int>>next(n+2,vector<int>(2,0));
        
        for(int i=1;i<=n;i++)
            prev[i][0]=prev[i-1][0]+(s[i-1]=='0'),prev[i][1]=prev[i-1][1]+(s[i-1]=='1');
        
        for(int i=n;i>0;i--)
            next[i][0]=next[i+1][0]+(s[i-1]=='0'),next[i][1]=next[i+1][1]+(s[i-1]=='1');
        
        ll ways=0;
        for(int i=1;i<=n;i++)
        {
            int compliment=1-(s[i-1]-'0');
            ways+=1LL*prev[i-1][compliment]*next[i+1][compliment];
        }
        
        return ways;
    }
};