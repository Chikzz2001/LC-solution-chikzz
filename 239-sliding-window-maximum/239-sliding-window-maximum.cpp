class Solution {
    vector<int>seg_tree;
    void build(vector<int>& nums,int node,int start,int end)
    {
        if(start>end)return;
    
        if(start==end)
        {seg_tree[node]=nums[start];return;}
        
        int mid=(start+end)/2;
        build(nums,2*node,start,mid);
        build(nums,2*node+1,mid+1,end);
        seg_tree[node]=max(seg_tree[node*2],seg_tree[node*2+1]);
    }
    
    int range_max(int node,int start,int end,int l,int r)
    {
        if(start>end)return -1e7;
        
        if(end<l||start>r)return -1e7;
        
        if(start==end)
            return seg_tree[node];
        
        if(start>=l&&end<=r)
            return seg_tree[node];
        
        int mid=(start+end)/2;
        int left=range_max(node*2,start,mid,l,r);
        int right=range_max(node*2+1,mid+1,end,l,r);
        return max(left,right);
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        seg_tree=vector<int>(4*n,-1e7);
        build(nums,1,0,n-1);
        // for(int i=0;i<4*n;i++)
        //     cout<<seg_tree[i]<<" ";
        vector<int>res;
        for(int i=0;i<=n-k;i++)
        {
            res.push_back(range_max(1,0,n-1,i,i+k-1));
        }
        return res;
    }
};