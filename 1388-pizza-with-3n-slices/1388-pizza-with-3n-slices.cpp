class Solution {
    int dp[501][170];
    int helper(vector<int>& slices,int i,int left)
    {
        if(i>=slices.size())return left==0?0:-1e7;
         if(left==0)return 0;
        
        if(dp[i][left]!=-1)
            return dp[i][left];
        
        return dp[i][left]=max(slices[i]+helper(slices,i+2,left-1),helper(slices,i+1,left));
    }
public:
    int maxSizeSlices(vector<int>& slices) 
    {
        int n=slices.size();
        if(n==1)return slices[0];
        if(n==2)return max(slices[0],slices[1]);
        if(n==3)return max({slices[0],slices[1],slices[2]});
        memset(dp,-1,sizeof(dp));
        int res1=helper(slices,1,n/3);
        memset(dp,-1,sizeof(dp));
        slices[n-1]=0;
        int res2=helper(slices,0,n/3);
        return max(res1,res2);
    }
};

/*
1 2 3 4 5
1 2 4 6
2 3 4 5 6
2 3 6 8 
*/