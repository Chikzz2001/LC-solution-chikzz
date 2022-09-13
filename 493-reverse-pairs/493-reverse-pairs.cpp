class Solution {
    void merge(vector<int>& nums,int s,int mid,int e)
    {
        vector<int>temp;
        int i=s,j=mid+1;
        while(i<=mid&&j<=e)
        {
            if(nums[i]<nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while(i<=mid)
            temp.push_back(nums[i++]);
        while(j<=e)
            temp.push_back(nums[j++]);
        
        for(int i=0;i<temp.size();i++)
            nums[i+s]=temp[i];
    }
    int noOfPairs(vector<int>& nums,int s,int e)
    {
        //if s>e then invalid range hence return
        if(s>=e)return 0;
        
        int mid=s+(e-s)/2;
        int left=noOfPairs(nums,s,mid);
        int right=noOfPairs(nums,mid+1,e);
        
        int left_ptr=s,right_ptr=mid+1;
        //the left and the right partitions will be sorted now we need to find pairs which
        //satisfy nums[i]>2*nums[j] where i<j
        //as all partitions in the left half are sorted we can say if for certain i nums[i]>2*nums[j]
        //then all eles from i to mid satisfy that for particular j and then we can move our j pointer
        //to check the next first valid occurence of reverse pair
        
        int res=0;
        while(right_ptr<=e)
        {
            while(left_ptr<=mid&&nums[left_ptr]<=2LL*nums[right_ptr])
                left_ptr++;
            res+=(mid-left_ptr+1);
            right_ptr++;
        }
        
        merge(nums,s,mid,e);
        return res+left+right;
    }
public:
    int reversePairs(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        return noOfPairs(nums,s,e);
    }
};