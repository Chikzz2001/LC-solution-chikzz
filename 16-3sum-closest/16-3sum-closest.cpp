class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(),nums.end());
            int res=0,minn=INT_MAX;
            for(int i=0;i<nums.size();i++)
            {
                int lo=i+1;
                int hi=nums.size()-1;
                while (lo<hi)
                {
                    int sum=nums[i]+nums[lo]+nums[hi];
                    if(sum<target)
                    {
                        if(abs(sum-target)<minn)
                        {
                            minn=abs(sum-target);
                            res=sum;
                        }
                        lo++;
                    }
                    else if(sum>target)
                    {
                        if(abs(sum-target)<minn)
                        {
                            minn=abs(sum-target);
                            res=sum;
                        }
                        hi--;
                    }
                    else
                    {
                        return target;
                    }
                }
                while (i+1<nums.size()&&nums[i+1]==nums[i])
                    i++;
            }

            return res;
        }
};