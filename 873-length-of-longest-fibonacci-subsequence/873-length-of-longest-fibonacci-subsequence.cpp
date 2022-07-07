class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int n=arr.size();
        map<int,int>m;
        int res=0;
        m[arr[0]]=0,m[arr[1]]=1;
        for(int i=2;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(m.count(arr[i]-arr[j])&&m[arr[i]-arr[j]]<j)
                {
                    int f=m[arr[i]-arr[j]],s=j;
                    int c=2;
                    while(1)
                    {
                        c++;
                        if(m.count(arr[s]-arr[f])&&m[arr[s]-arr[f]]<f)
                        {
                            int t=s;
                            s=f;
                            f=m[arr[t]-arr[s]];
                        }
                        else
                            break;
                    }
                    res=max(res,c);
                }
            }
            m[arr[i]]=i;
        }
        return res;
    }
};