class Solution {
public:
    int numSquares(int n) {
        
        int dp[n+1];
        
        vector<int>squares;
        
        for(int i=1;i<=n;i++)
        {
            if((int)sqrt(i)*(int)sqrt(i)==i)
            {
                squares.push_back(i);
                dp[i]=1;
            }
            else
            {int minn=i;
                for(int j=0;j<squares.size();j++)
                {
                    minn=min(minn,1+dp[i-squares[j]]);
                }
             dp[i]=minn;
            }
        }
        // for(int &s:squares)cout<<s<<" ";
        //for(auto &x:dp)cout<<x<<" ";
        return dp[n];
    }
};