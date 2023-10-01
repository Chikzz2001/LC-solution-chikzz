//FOR INFINITE APPEND OF STRING/ARRAY MAKE IT DOUBLE AND CHECK AS IN A DOUBLE ARRAY WE GET ALL 
//POSSIBLE SUBARRAYS WE CAN GET IN AN INFINITE CONCATENATION OF THE ARRAY

#define ll long long
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        ll s=0;
        for(int x:nums)s+=1ll*x;
        
        int tot=target/s;
        
        vector<int>v=nums;
        for(int x:nums)v.push_back(x);
        
        //checking if target%s present with 2xnums
        map<ll,int>m;
        ll pre=0;
        m[0]=-1;
        int r=1e9;
        int res=1e9;
       for(int i=0;i<v.size();i++) {
           pre+=v[i];
           if(m.count(pre-target)) {
               r=min(r,i-m[pre-target]);
           }
           m[pre]=i;
       }
        if(r!=1e9)res=r;
    
        //so we also can have the pattern as nums(suf) nums nums nums.....(tot times) nums(pre)
        //so search max subarray with s-target%s sum and n-r would be my suf+pre  
        target=s-target%s;

        m.clear();
        m[0]=-1;
        r=-1;
        pre=0;
        for(int i=0;i<v.size();i++) {
           pre+=v[i];
           if(m.count(pre-target)) {
               r=max(r,i-m[pre-target]);
           }
            if(!m.count(pre))
            m[pre]=i;
       }
    
        int n=nums.size();
        if(r!=-1) {
            res=min(res,(tot*n)+(n-r));
        }
        
        return res==1e9?-1:res;
    }
};
