//the basic idea is to for each ele u have to find the no of subarrays containing it as the subarray's min value
//how to do it?
//--->count the max length of subarray starting from the prev ele at its left-->say lg
//--->count the max length of subarray starting from the next ele at its right-->say rg
        
//then total number of subarrays become 1(ele under consideration)+lg+rg+lg*rg
//find these lengths using the concept of next and prev smaller ele using stack
        
//Now this sounds fair for distinct eles but what will we do if array contains equal eles?
//well, we can consider taking equal greater and equal for one side and strictly greater ele for the other side
        
//REST OF THE PART U WILL UNDERSTAND BY FOLLOWING THE CODE.

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
        
        ll res=0;
        for(int i=0;i<n;i++)
        {
            res=res%M+((1LL*arr[i])%M*(1+lg[i]%M+rg[i]%M+(lg[i]%M*rg[i]%M)%M)%M)%M;
        }
        return res;
    }
};