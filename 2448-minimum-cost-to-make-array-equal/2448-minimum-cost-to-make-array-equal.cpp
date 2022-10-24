#define ll long long int
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //1 3 5 2
    
        //1-->0+2*3+4*1+1*14=24
        //2-->1*2+1*3+3*1+0=8
        //3-->2*2+3*0+2*1+1*14=20
        //4-->3*2+1*3+1*1+2*14=38
        //5-->4*2+2*3+0+3*14=56
        //poynomial curve with a minima --->use ternary searcch to find the point
        int lo=*min_element(nums.begin(),nums.end()),hi=*max_element(nums.begin(),nums.end());
        long long res=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            ll f_prev=0,f_next=0,f_curr=0;
            
            for(int i=0;i<nums.size();i++)
                f_prev+=1LL*abs(mid-1-nums[i])*cost[i];
            for(int i=0;i<nums.size();i++)
                f_curr+=1LL*abs(mid-nums[i])*cost[i];
            for(int i=0;i<nums.size();i++)
                f_next+=1LL*abs(mid+1-nums[i])*cost[i];
            
            // cout<<mid<<" "<<f_curr<<"\n";
            // cout<<mid-1<<" "<<f_prev<<"\n";
            // cout<<mid+1<<" "<<f_next<<"\n";
            if(f_prev<f_curr&&f_curr<f_next)
                hi=mid-1;
            else if(f_prev>f_curr&&f_curr>f_next)
                lo=mid+1;
            else
                return f_curr;
        }
        ll start=0,last=0;
        lo=*min_element(nums.begin(),nums.end()),hi=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
                start+=1LL*abs(lo-nums[i])*cost[i];
        for(int i=0;i<nums.size();i++)
                last+=1LL*abs(hi-nums[i])*cost[i];
        
        return min(start,last);
    }
};