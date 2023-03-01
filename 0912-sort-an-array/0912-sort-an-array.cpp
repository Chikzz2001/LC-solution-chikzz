class Solution {
    vector<int> merge(vector<int>& v1,vector<int>& v2)
    {
        int n=v1.size(),m=v2.size();
        if(n==0||m==0)return n==0?v2:v1;
        
        vector<int>res;
        
        int v1idx=0,v2idx=0;
        while(v1idx<n&&v2idx<m)
        {
            if(v1[v1idx]<v2[v2idx])
            {
               res.push_back(v1[v1idx]);
                v1idx++;
            }
            else
            {
               res.push_back(v2[v2idx]);
                v2idx++;
            }
        }
        if(v1idx==n)
        {
           for(int i=v2idx;i<m;i++)
            res.push_back(v2[i]);
        }
        if(v2idx==m)
        {
           for(int i=v1idx;i<n;i++)
            res.push_back(v1[i]); 
        }
        
        return res;
    }
    vector<int> sort(vector<int>& nums,int start,int end)
    {
        vector<int>res;
        
        if(start>end)
            return res;
        
        if(start==end)
        {
            res.push_back(nums[start]);
            return res;
        }
        
        int mid=start+(end-start)/2;
        
        vector<int>left=sort(nums,start,mid);
        vector<int>right=sort(nums,mid+1,end);
        
        res=merge(left,right);
        
        return res;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        return sort(nums,0,n-1);
    }
};