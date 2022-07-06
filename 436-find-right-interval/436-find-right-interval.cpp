class Solution {
    struct node
    {
        int s,e,i;
    };
    int LowerBound(vector<node>& v,int val)
    {
        int lo=0,hi=v.size()-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(v[mid].s>=val)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return v[lo].i;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& in) 
    {
        vector<node>v;
        for(int i=0;i<in.size();i++)
            v.push_back({in[i][0],in[i][1],i});
        
        sort(v.begin(),v.end(),[&](const node& v1,const node& v2)
             {
                 return v1.s<v2.s;
             });
        
        vector<int>res(in.size());
        for(int i=0;i<in.size();i++)
        {
            if(v[i].e>v.back().s)
            {res[v[i].i]=-1;continue;}
            int idx=LowerBound(v,v[i].e);
            res[v[i].i]=idx;
        }
        return res;
    }
};