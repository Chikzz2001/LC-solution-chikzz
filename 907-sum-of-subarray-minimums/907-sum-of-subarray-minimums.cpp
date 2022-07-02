#define ll long long int
class Solution {
    const int M=1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n=arr.size();
        ll lg[n],rg[n];
        
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>arr[i])
                st.pop();
            
            lg[i]=st.empty()?i:i-st.top()-1;
            st.push(i);
        }
        
        while(st.size())st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
                st.pop();
            
            rg[i]=st.empty()?n-1-i:st.top()-i-1;
            st.push(i);
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<lg[i]<<" "<<rg[i]<<"\n";
        ll res=0;
        for(int i=0;i<n;i++)
        {
            res=res%M+((1LL*arr[i])%M*(1+lg[i]%M+rg[i]%M+(lg[i]%M*rg[i]%M)%M)%M)%M;
        }
        return res;
    }
};