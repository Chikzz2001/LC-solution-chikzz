class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
       map<int,int>freq;
        freq[0]=1;
        
        for(auto &x:nums)
        {
            x%=k;
            if(x<0)x=(x+k)%k;
        }
        
        int pre=0,res=0;
        for(auto &x:nums)
        {
            pre+=x;
            int rem=pre%k;
            if(freq.count(rem))
                res+=freq[rem];
            freq[rem]++;
            if(pre>k)pre%=k;
        }
        return res;
    }
};

//4 5 0 -2 -3 1
//4 4 4   
