class Solution {
    bool check(vector<int>& v,int mid,int k)
    {
        int sum=0;
        for(int i=0;i<mid;i++)
        {
            sum+=v[i];
        }
        if(sum<=k)return 1;
        for(int i=1;i<=v.size()-mid;i++)
        {
            sum-=v[i-1];
            sum+=v[i+mid-1];
            if(sum<=k)return 1;
        }
        return 0;
    }
    int func(vector<int>& v,int k)
    {
        int n=v.size();
        int lo=0,hi=n,res=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(v,mid,k))
            {
                res=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        return res;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();
        vector<int>v(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(answerKey[i]=='T')v[i]=1;
        }
        
        int res=func(v,k);
        for(int i=0;i<n;i++)
            v[i]=1-v[i];
        res=max(res,func(v,k));
        return res;
    }
};