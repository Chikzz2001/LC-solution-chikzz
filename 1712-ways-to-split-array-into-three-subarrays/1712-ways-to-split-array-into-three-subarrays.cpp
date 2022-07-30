class Solution {
    const int M=1e9+7;
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        
        //calculate the prefix-sum array
        for(int i=1;i<n;i++)
            nums[i]+=nums[i-1];
        
        int count=0;
        for(int i=0;i<=n-1;i++)
        {
            //we need to have at least one element in the 1st and 3rd group so we consider lo=i+1 && hi=n-2
            int lo=i+1,hi=n-2,right=-1,left=-1;
    
            //we calculate the right-most valid index
            while(lo<=hi)
            {
                int mid=lo+(hi-lo)/2;
                if(nums[mid]-nums[i]<=nums.back()-nums[mid])
                {
                    right=mid;
                    lo=mid+1;
                }
                else
                    hi=mid-1;
            }
            
            lo=i+1;hi=n-2;
            //we calculate the left-most valid index
             while(lo<=hi)
            {
                int mid=lo+(hi-lo)/2;
                if(nums[i]<=nums[mid]-nums[i])
                {
                    left=mid;
                    hi=mid-1;
                }
                else
                    lo=mid+1;
            }
            //invalid condition check i.e. if one of the bound does not exist 
            //or left bound is greater than right bound
            if(left==-1||right==-1||left>right)continue;
            
            count=(count+(right-left+1)%M)%M;
        }
        return count%M;
    }
};