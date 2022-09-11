#define ll long long int
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        //(s1+s2+s3+s4+...sn)*min(e1,e2,e3,....en)
       
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
            v.push_back({efficiency[i],speed[i]});
        sort(v.begin(),v.end(),[&](const vector<int>& v1,const vector<int>& v2)
             {
                 return v1[0]>v2[0];
             });
        //speed=v[1],efficiency=v[0];
       
        priority_queue<int>pq;
        
        ll S=0,res=0;
        for(auto &it:v)
        {
            S+=it[1];
            pq.push(-it[1]);
            
            while(pq.size()>k)
            {
                S+=pq.top();
                pq.pop();
            }
            
            res=max(res,S*it[0]);
        }
        return res%1000000007;
    }
};


/*

e1 e2 e3 e4.................. en-->decreasing order

take k highest speed at every instance for every e


*/