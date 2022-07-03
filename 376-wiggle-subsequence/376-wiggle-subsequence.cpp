class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ma=1,mi=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
                mi=ma+1;
            else if(nums[i-1]<nums[i])
                ma=mi+1;
            else
                continue;
        }
        return max(mi,ma);
    }
};

//ma: 1 17 10 13 15 16-->ma sees the current no. of peaks that is uphill

//mi: 5 10 5 8--->mi sees the current no. of peaks that is downhill

//so when we see an uphill we take the current no of hills(2*downhill this time) (when we get an ma we are sure
//that mi is the max no of count of downhills till that point) so we do ma=mi+1

//similarly when we see a downhill we are sure there is a sequence with one uphill present at the end 
//so mi=ma+1