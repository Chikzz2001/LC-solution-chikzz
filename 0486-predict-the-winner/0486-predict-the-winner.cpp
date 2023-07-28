class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        /*
            1 5 2
            take 1-->5 2            take 2-->1 5
            1+2                     2+1
            
            dp[i][j]-->states what maximum sum can player 1 bring (from the range i-->j) if both    
            players play optimally
        */
        
        int n=nums.size();
        int dp[n][n];
        
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=i+g;j<n;i++,j++)
            {
                if(g==0)
                    dp[i][j]=nums[i];
                else if(g==1)
                    dp[i][j]=max(nums[i],nums[j]);
                else
                {
                    //for player2 to earn max sum he has to make player1 have min sum
                    //from the set he would leave
                    
                    //optimal way by which player2 can pickup ele from set(i+1,j)
                    int op1=min(dp[i+1][j-1],dp[i+2][j]);
                    //optimal way by which player2 can pickup ele from set(i,j-1)
                    int op2=min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j]=max(nums[i]+op1,nums[j]+op2);
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        
        return (2*dp[0][n-1])>=sum;
    }
};