class Solution {
    vector<int>seg_tree;
    void build(int node,int s,int e,vector<int>& nums)
    {
        if(s>e)return;
        if(s==e){seg_tree[node]=nums[s];return;}
        int mid=s+(e-s)/2;
        build(2*node,s,mid,nums);
        build(2*node+1,mid+1,e,nums);
        seg_tree[node]=seg_tree[2*node]|seg_tree[2*node+1];
    }
    int range_OR(int node,int s,int e,int l,int r)
    {
        if(s>e||e<l||s>r)
            return 0;
        if(s>=l&&e<=r||s==e)return seg_tree[node];
        
        int mid=s+(e-s)/2;
        int left_OR=range_OR(2*node,s,mid,l,r);
        int right_OR=range_OR(2*node+1,mid+1,e,l,r);
        return left_OR|right_OR;
    }
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        v[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)v[i]=nums[i]|v[i+1];
        
        seg_tree=vector<int>(4*n);
        build(1,0,n-1,nums);
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            int max_OR=v[i];
            int lo=i,hi=n-1;
            while(lo<=hi)
            {
                int mid=lo+(hi-lo)/2;
                int rangeOR=range_OR(1,0,n-1,i,mid);
                if(rangeOR<max_OR)
                    lo=mid+1;
                else
                    hi=mid-1;
            }
            res[i]=lo-i+1;
        }
        return res;
    }
};