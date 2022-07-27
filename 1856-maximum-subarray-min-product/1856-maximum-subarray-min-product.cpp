#define ll long long int
class Solution {
    const int M=1e9+7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        stack<int>next_s,prev_s;
        
        int n=nums.size();
        vector<int>ns(n),ps(n);
        
        for(int i=0;i<n;i++)
        {
            while(!prev_s.empty()&&nums[prev_s.top()]>=nums[i])
                prev_s.pop();
            int idx=prev_s.empty()?-1:prev_s.top();
            ps[i]=idx;
            prev_s.push(i);
        }
        
         for(int i=n-1;i>=0;i--)
        {
            while(!next_s.empty()&&nums[next_s.top()]>nums[i])
                next_s.pop();
            int idx=next_s.empty()?n:next_s.top();
             ns[i]=idx;
            next_s.push(i);
        }
        
        ll presum[n];
        presum[0]=nums[0];
        for(int i=1;i<n;i++)presum[i]=presum[i-1]+nums[i];
        
        ll maxx=0;
        for(int i=0;i<n;i++)
        {
            //cout<<i<<" "<<ps[i]<<" "<<ns[i]<<"\n";
            maxx=max(maxx,(1LL*(presum[ns[i]-1]-(ps[i]==-1?0LL:presum[ps[i]]))*nums[i]));
        }
        
        return maxx%M;
    }
};