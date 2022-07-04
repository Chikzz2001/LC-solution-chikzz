class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        //1 2 3 4 0 0 1 2 3 4
        //0 0 1 1 2 2 3 3 4 4
        
        int perfect_divisible=0;
        for(auto &x:arr)
        {
            x%=k;
            x=(x+k)%k;
            if(x==0)perfect_divisible++;
        }
        
        if(perfect_divisible&1)return 0;
        
        sort(arr.begin(),arr.end());
        
        int n=arr.size(),lo=perfect_divisible,hi=n-1;
        while(lo<hi)
        {
            if((arr[lo]+arr[hi])%k)
                return 0;
            lo++;
            hi--;
        }
        return 1;
    }
};