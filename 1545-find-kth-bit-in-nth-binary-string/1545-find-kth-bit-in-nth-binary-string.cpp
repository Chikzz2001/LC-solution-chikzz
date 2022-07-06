class Solution {
    char f(int n,int k)
    {
        if(n==1)return '0';
        
//         if(dp[k][n]!='#')
//             return dp[k][n];
        
        int half=1<<(n-1);
        if(k==half)
            return '1';
        
        if(k<half)
        {
            return f(n-1,k);
        }
        else
        {
            return f(n-1,2*half-k)=='1'?'0':'1';
        }
    }
public:
    char findKthBit(int n, int k) 
    {
        //vector<vector<char>>dp(k+1,vector<char>(n+1,'#'));
        return f(n,k);
    }
};
