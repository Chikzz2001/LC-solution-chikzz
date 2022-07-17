class Solution {
    bool check(vector<int>& nums,int mid,int limit)
    {
        int i=0,n=nums.size();
        if(mid==1)
            return 1;
        
        deque<int>small,large;
        
        while(i<n)
        {
           if(small.size()&&small.front()==i-mid)
               small.pop_front();
            
            if(large.size()&&large.front()==i-mid)
               large.pop_front();
            
            while(small.size()&&nums[small.back()]>=nums[i])
                small.pop_back();
            
            while(large.size()&&nums[large.back()]<=nums[i])
                large.pop_back();
            
            small.push_back(i);
            large.push_back(i);
            
            if(i>=mid-1)
            {
                 //cout<<mid<<" "<<large.front()<<" "<<small.front()<<"\n";
                 if(nums[large.front()]-nums[small.front()]<=limit)
            {
                return 1;
            }
            }
            i++;
        }
        
        return 0;
    }
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n=nums.size();
        int lo=1,hi=n,res=-1;
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            
            if(check(nums,mid,limit))
            {
                res=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        
        return res;
    }
};