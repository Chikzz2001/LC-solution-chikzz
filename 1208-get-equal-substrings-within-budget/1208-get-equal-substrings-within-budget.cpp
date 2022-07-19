class Solution {
    bool valid(string &s,string &t,int &cost,int window)
    {
        int sum=0;
        for(int i=0;i<window;i++)
            sum+=abs(s[i]-t[i]);
        
        if(sum<=cost)return 1;
        for(int i=1;i<=s.length()-window;i++)
        {
            sum-=abs(s[i-1]-t[i-1]);
            sum+=abs(s[i+window-1]-t[i+window-1]);
            if(sum<=cost)return 1;
        }
        return 0;
    }
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int lo=1,hi=s.length(),res=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(valid(s,t,maxCost,mid))
            {
                res=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return res;
    }
};