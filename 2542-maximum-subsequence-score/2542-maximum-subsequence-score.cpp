#define ll long long int
#define ff first
#define ss second
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        ll res=0;
        ll s=0;
        priority_queue<int>pq;
     
        for(int i=0;i<k;i++){s+=v[i].ss;pq.push(-v[i].ss);}
        
        for(int i=0;i<=n-k;i++)
        {
            if(i!=0)
            {
                s+=v[i+k-1].ss;
                pq.push(-v[i+k-1].ss);
                s+=pq.top();
                pq.pop();
            }
            res=max(res,1ll*v[i+k-1].ff*s);
        }
        return res;
    }
};