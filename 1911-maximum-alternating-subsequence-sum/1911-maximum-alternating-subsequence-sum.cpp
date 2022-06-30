#define ll long long int
class Solution {
//     ll dp[100001][2];
//     ll helper(vector<int>& nums,int op,int i)
//     {
//         if(i==nums.size())
//             return 0;
        
//         if(dp[i][op]!=-1)
//             return dp[i][op];
        
//         ll maxx=helper(nums,op,i+1);
        
//         if(op)
//             maxx=max(maxx,-nums[i]+helper(nums,0,i+1));
//         else
//             maxx=max(maxx,nums[i]+helper(nums,1,i+1));
        
//         return dp[i][op]=maxx;
//     }
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n=nums.size();
        //dp[i][j]-->max alt subseq sum till idx doin op[j] at tht idx
        ll pos=-1e6,neg=0;
        
        for(int i=1;i<=n;i++)
        {
            ll tpos=max(pos,neg+nums[i-1]);
            ll tneg=max(neg,pos-nums[i-1]);
            pos=tpos,neg=tneg;
        }
        
        return max(pos,neg);
    }
};

/*
    0 1 2 3 4
    i 4 2 7 7
    0 0 2 2 3
*/