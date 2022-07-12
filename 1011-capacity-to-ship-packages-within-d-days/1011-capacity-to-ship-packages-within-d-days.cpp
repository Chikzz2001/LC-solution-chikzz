class Solution {
    bool valid(vector<int>& weights,int days,int max_weight)
    {
        int count_days=0;
        int wt=0;
        for(int i=0;i<weights.size();i++)
        {
            if(wt+weights[i]>max_weight)
            {
                count_days++;
                wt=weights[i];
            }
            else
                wt+=weights[i];
            if(count_days>days)return 0;
        }
        count_days++;
        return count_days<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int max_weight=0,total_weight=0;
        for(auto &w:weights)total_weight+=w,max_weight=max(max_weight,w);
        
        int lo=max_weight;
        int hi=total_weight;
        
        int res;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(valid(weights,days,mid))
            {
                res=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return res;
    }
};