class Solution {
public:
    int minimumBuckets(string street) {
        int buckets=0;
        
        int n=street.length();
        for(int i=1;i<n-1;i++)
        {
            if(street[i]=='.')
            {
                if(street[i-1]=='H'&&street[i+1]=='H')
                {
                    buckets++;
                    street[i-1]=street[i+1]='#';
                }
            }
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(street[i]=='.'&&street[i+1]=='H')
            {
                buckets++;
                street[i+1]='#';
            }
        }
        
        for(int i=n-1;i>0;i--)
        {
            if(street[i]=='.'&&street[i-1]=='H')
            {
                buckets++;
                street[i-1]='#';
            }
        }
        
        bool isnotmarked=0;
        for(auto &s:street)
            isnotmarked+=(s=='H');
        
        return isnotmarked?-1:buckets;
    }
};

/*

.H.H-->MARKED
.HH.

*/