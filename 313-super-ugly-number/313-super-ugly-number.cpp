class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        vector<long long int>store(n);
        store[0]=1;
        
        int k=1;
        vector<int>pointers(primes.size(),0);
        while(k<n)
        {
            long long int minn=1e18;
            for(int i=0;i<primes.size();i++)
                minn=min(minn,1LL*primes[i]*store[pointers[i]]);
            
            store[k]=minn;
            for(int i=0;i<primes.size();i++)
            {
                if(minn==1LL*primes[i]*store[pointers[i]])
                    pointers[i]++;
            }
            k++;
        }    
        return store[n-1];
    }
};
