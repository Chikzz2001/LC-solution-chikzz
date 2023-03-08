class Solution {
    bool canEat(vector<int>& piles,int k,int h)
    {
        int time_taken=0;
        for(auto &p:piles)
        {
            if(!(p%k))
                time_taken+=p/k;
            else
                time_taken+=p/k+1;
            
            if(time_taken>h)
                return 0;
        }
        return 1;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int hi=*max_element(piles.begin(),piles.end());
        int lo=1;
        
        int res;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            
            if(canEat(piles,mid,h))
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