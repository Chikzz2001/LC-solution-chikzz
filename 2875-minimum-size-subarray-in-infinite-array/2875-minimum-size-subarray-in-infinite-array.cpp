#define ll long long
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long s=0;
        for(int x:nums)s+=1ll*x;
        int tot=target/s;
        int tar=target%s;
        vector<int>v=nums;
        for(int x:nums)v.push_back(x);
        // cout<<s<<" ";
        
        map<ll,int>m;
        ll pre=0;
        m[0]=-1;
        int r=1e9;
        int res=1e9;
       for(int i=0;i<v.size();i++) {
           pre+=v[i];
           //pre-tar
           if(m.count(pre-target)) {
               r=min(r,i-m[pre-target]);
           }
           m[pre]=i;
       }
        // cout<<r<<" ";
        if(r!=1e9)res=r;
        // cout<<target%s<<"\n";
        // cout<<tot;
        target=s-target%s;
        // cout<<target;
        m.clear();
        m[0]=-1;
        r=-1;
        pre=0;
        for(int i=0;i<v.size();i++) {
           pre+=v[i];
           //pre-tar
           if(m.count(pre-target)) {
               r=max(r,i-m[pre-target]);
           }
            if(!m.count(pre))
            m[pre]=i;
       }
        // cout<<r;
        int n=nums.size();
        if(r!=-1) {
            res=min(res,(tot*n)+(n-r));
        }
        
        return res==1e9?-1:res;
    }
};

//[2,1,5,7,7,1,6,3]
//39
// [1,2,2,2,1,2,1,2,1,2,1]
// 83