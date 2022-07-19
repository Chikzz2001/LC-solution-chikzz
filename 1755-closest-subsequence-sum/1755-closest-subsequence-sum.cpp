class Solution {
    vector<int> AllSubseqSums(vector<int>& nums,int s,int e)
    {
        int n=(e-s+1);
        vector<int>res;
        for(int i=0;i<(1<<n);i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1)
                {
                    sum+=nums[j+s];
                }
            }
            res.push_back(sum);
        }
        return res;
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) 
    {
        int n=nums.size();
        vector<int>first_half=AllSubseqSums(nums,0,(n-1)/2);
        vector<int>second_half=AllSubseqSums(nums,(n-1)/2+1,n-1);
        sort(second_half.begin(),second_half.end());
        
        int min_diff=1e9;
        int size=second_half.size();
        for(int i=0;i<first_half.size();i++)
        {
            //|sum-goal|-->S1+S2-goal/goal-(S1+S2)
            //S2=goal-S1
            int target=goal-first_half[i];
            int idx1=lower_bound(second_half.begin(),second_half.end(),target)-second_half.begin();
            if(idx1<size&&second_half[idx1]==target)return 0;
            if(idx1<size)
            min_diff=min(min_diff,second_half[idx1]-target);
            idx1--;
            if(idx1>=0)
                min_diff=min(min_diff,target-second_half[idx1]);
        }
        return min_diff;
    }
};