class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        /*
        
        //10010001111010
        //00101100110001
        
        &-00000000110000
        |-10111101111011
        
        */
        
        
        vector<int>cnt;
        long long res=0;
        map<int,int>m,bitz;
        for(auto &x:nums)
        {
            int bits=0;
            if(m.count(x))continue;
            for(int i=0;i<32;i++)
            {
                if((x>>i)&1)
                    bits++;
            }
            cnt.push_back(bits);
            m[x]++;
            bitz[x]=bits;
        }
        
        sort(cnt.begin(),cnt.end());
        
        for(auto &x:cnt)
        {
            int idx=lower_bound(cnt.begin(),cnt.end(),k-x)-cnt.begin();
            res+=1LL*(cnt.size()-idx);
        }
        
        for(auto &[x,y]:m)
        {
            if(2*bitz[x]>=k&&y>1)
                res++;
        }
        return res;
    
    }
};