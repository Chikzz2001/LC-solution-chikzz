#define ll long long int
class Solution {
    const int M=1e9+7;
    ll helper(int n)
    {
        if(n==1)return 1;
        ll val=helper(n-1);
        string s;
        for(int i=log2(n);i>=0;i--)
        {
            val=((val%M)*2)%M;
            if(n&(1<<i))
            {
                val=(val+1)%M;
            }
        }
//         reverse(s.begin(),s.end());
//         //cout<<n<<" "<<s<<"\n";
//         for(auto &x:s)
//         {
            
//             if(x=='1')
                
//         }
        return val%M;
    }
public:
    int concatenatedBinary(int n) 
    {
        return helper(n)%M;
    }
};