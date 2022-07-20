#define ll long long int
class Solution {
    const int M=1e9+7;
    map<int,ll>BTs;
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        
        BTs[arr[0]]=1LL;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            BTs[arr[i]]=1LL;
            for(int j=0;1LL*arr[j]*arr[j]<=1LL*arr[i];j++)
            {
                if(arr[i]%arr[j]==0&&BTs.count(arr[i]/arr[j]))
                {
                    if(arr[j]*arr[j]!=arr[i])
                    BTs[arr[i]]=BTs[arr[i]]%M+(2LL*BTs[arr[j]]%M*BTs[arr[i]/arr[j]]%M)%M;
                    else
                        BTs[arr[i]]=BTs[arr[i]]%M+(1LL*BTs[arr[j]]%M*BTs[arr[i]/arr[j]]%M)%M;
                }
            }
        }
        
        ll res=0;
        for(int i=0;i<n;i++)
           res=(res%M+BTs[arr[i]]%M)%M;
        
        return res;
    }
};