class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if(k<2)return 0;
        
        int i=0,j=0,c=0;
        long long int p=1;
        
        int n=nums.size();
        while(j<n)
        {
            p*=nums[j];
            
            while(i<j&&p>=k)
                p/=nums[i++];
            
            c+=(p<k?(j-i+1):0);
            j++;
        }
        return c;
    }
};
