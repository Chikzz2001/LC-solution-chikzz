class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        vector<int>v(5,0);
        int res=-1;
        for(auto &ch:croakOfFrogs)
        {
            if(ch=='c')
                v[0]++;
            else if(ch=='r')
                v[1]++;
            else if(ch=='o')
                v[2]++;
            else if(ch=='a')
                v[3]++;
            else
                v[4]++;
            
           int minn=1e6;
            for(int i=0;i<5;i++)
            {
                if(i>0&&v[i]>v[i-1])
                    return -1;
                minn=min(minn,v[i]);
            }
            res=max(res,v[0]);
            
            for(int i=0;i<5;i++)
                v[i]-=minn;
        }
        
        for(int i=1;i<5;i++)
        {
            if(v[i]!=v[i-1])return -1;
        }
        return res;
    }
};