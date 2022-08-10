class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        
        int res=0;
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;)
            {
                if(nums1[i]==nums2[j])
                {
                    int k=j;
                    int len=0;
                    while(i<n&&k<m&&nums1[i]==nums2[k])
                        i++,k++,len++;
                    if(len>res)
                    {
                        //cout<<i<<" "<<j<<" "<<len<<"\n";
                        res=max(res,len);
                    }
                    
                }
                else
                    i++;
            }
        }
        
         for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;)
            {
                if(nums1[j]==nums2[i])
                {
                    int k=j;
                    int len=0;
                    while(i<m&&k<n&&nums2[i]==nums1[k])
                        i++,k++,len++;
                    if(len>res)
                    {
                        //cout<<i<<" "<<j<<" "<<len<<"\n";
                        res=max(res,len);
                    }
                    
                }
                else
                    i++;
            }
        }
        return res;
    }
};

/*

[0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,1,0,0,0,1]
[1,0,1,1,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0]

*/