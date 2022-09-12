class Solution {
    vector<int>seg_tree;
    void update(int node,int start,int end,int val,int new_val)
    {
        if(start>end||end<val||start>val)return;
        
        seg_tree[node]=max(seg_tree[node],new_val);
        if(start==end)return;
        
        int mid=(start+end)/2;
        
        update(2*node,start,mid,val,new_val);
        update(2*node+1,mid+1,end,val,new_val);
    }
    
    int range_max(int node,int start,int end,int l,int r)
    {
        if(start>r||end<l||start>end)return 0;
        
        if(start==end||l<=start&&end<=r)return seg_tree[node];
        
        int mid=(start+end)/2;
        
        int left=range_max(2*node,start,mid,l,r);
        int right=range_max(2*node+1,mid+1,end,l,r);
        return max(left,right);
    }
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int LIS=0;
        int n=nums.size();
        int maxx=*max_element(nums.begin(),nums.end());
        seg_tree=vector<int>(4*(maxx+1),0);
        
        for(int i=0;i<n;i++)
        {
            int max_value=range_max(1,0,maxx,max(0,nums[i]-k),nums[i]-1);
            //cout<<i<<" "<<max_value<<"\n";
            LIS=max(LIS,1+max_value);
            
            update(1,0,maxx,nums[i],1+max_value);
        }
       
        return LIS;
    }
};