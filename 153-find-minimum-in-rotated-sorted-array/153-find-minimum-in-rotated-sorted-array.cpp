class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int lo=0,hi=nums.size()-1;
        if(lo==hi)
            return nums[lo];
      
        //This condition implies that the array is sorted i.e., no shift is made
        //hence we just return the first value of the array
        if(nums[lo]<nums[hi])
            return nums[lo];
        
       //the worst case that we can get is if the last element is the min element
       //that is array is shifted by only one position
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
           
            //the pivot is identified if we get such an instance where 
            //a[i]>a[i+1] we immediately return a[i+1] 
            
            //we keep this condition first ---> we can see from 5,1,2,3,4
            //when lo=0 and hi=1 we get mid as 0 so mid-1 will give out of bound exception
            //hence we check this condition first so that nums[0]>nums[1]
            //is satisfied and we return the ans
            if(nums[mid]>nums[mid+1])
                return nums[mid+1];
            
            if(nums[mid-1]>nums[mid])
                return nums[mid];
            
            if(nums[lo]<=nums[mid])
                lo=mid+1;
            else if(nums[mid]<=nums[hi])
                hi=mid-1;
        }
        return 0;
    }
};

/*



x5 x1 x2 x3 x4
mid-1 does not exist

*/