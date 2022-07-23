class Solution {
    class BIT
    {
        int *bit_array;
        int N;
        public:
        BIT(int n)
        {
            N=n+1;
            bit_array=new int[n+2];
            for(int i=0;i<=n+1;i++)
                bit_array[i]=0;
        }
        
        void update(int idx)
        {
            for(int i=idx+1;i<=N;i+=(i&-i))
            {
                bit_array[i]++;
            }
        }
        
        int RangeSum(int left,int right)
        {
            if(left!=1)
            return RangeSum(1,right)-RangeSum(1,left);
            
            int sum=0;
            for(int i=right+1;i>=1;i-=(i&-i))
            {
                sum+=bit_array[i];
            }
            return sum;
        }
    };
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int minn=*min_element(nums.begin(),nums.end());
        
        int n=nums.size();
        if(minn<0)
        {
           for(int i=0;i<n;i++)
            nums[i]-=minn; 
        }
        
        int maxx=*max_element(nums.begin(),nums.end());
        int mini=1e9;
        
        BIT bit(maxx);
    
        vector<int>res(n,0);
        
        for(int i=n-1;i>=0;i--)
        {
            mini=min(mini,nums[i]);
            bit.update(nums[i]);
            
            res[i]=bit.RangeSum(mini-1,nums[i]-1);
        }
        
        return res;
    }
};