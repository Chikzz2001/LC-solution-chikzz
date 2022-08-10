class Solution {
    map<char,int>m;
    bool valid(map<char,int> t,int len,int n)
    {
        int compensate=0;
        for(auto &[x,y]:t)
        {
            //cout<<x<<" "<<y<<"\n";
            compensate+=max(0,n/4-y);
        }
        //cout<<len<<" "<<compensate<<"\n";
        return compensate<=len;
    }
    bool check(string &s,int len,int n)
    {
        map<char,int>t=m;
        for(int i=0;i<len;i++)
        {
            t[s[i]]--;
        }
        if(valid(t,len,n))return 1;
        for(int i=1;i<=n-len;i++)
        {
            t[s[i-1]]++;
            t[s[i+len-1]]--;
            if(valid(t,len,n))return 1;
        }
        return 0;
    }
public:
    int balancedString(string s) {
        m['Q']=m['W']=m['E']=m['R']=0;
        for(auto &ch:s)
            m[ch]++;
        
        bool f=1;
        int n=s.length();
        for(auto &[x,y]:m)
        {
            if(y!=n/4){f=0;break;}
        }
        if(f)return 0;
        //Q:3 W:1 E:0 R:0
        
        int lo=1,hi=n,res;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(s,mid,n))
            {
                res=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return res;
    }
};