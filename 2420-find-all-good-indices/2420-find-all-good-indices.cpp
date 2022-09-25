class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) 
    {
        //2 1 1 1 3 
        //a b c d e f
        //a>=b>=c<=d<=e--->b>=c>=d<=e<=f
        int n=nums.size();
        vector<int>pref_inc(n),suff_dec(n);
        for(int i=1;i<n;i++)
            pref_inc[i]=pref_inc[i-1]+(nums[i]>=nums[i-1]?1:0);
        for(int i=n-2;i>=0;i--)
            suff_dec[i]=suff_dec[i+1]+(nums[i]>=nums[i+1]?1:0);
        
        //2,1,1,1,3,4,1
        //0 0 1 2 3 4 4
        //4 3 2 1 1 1 0
        
        // for(auto &x:pref_inc)cout<<x<<" ";
        // cout<<"\n";
        // for(auto &x:suff_dec)cout<<x<<" ";
        vector<int>res;
        for(int i=k;i<n-k;i++)
        {
            if(pref_inc[i+k]-pref_inc[i+1]==k-1&&suff_dec[i-k]-suff_dec[i-1]==k-1)
                res.push_back(i);
        }
        return res;
    }
};

/*

[878724,201541,179099,98437,35765,327555,475851,598885,849470,943442]
4

*/