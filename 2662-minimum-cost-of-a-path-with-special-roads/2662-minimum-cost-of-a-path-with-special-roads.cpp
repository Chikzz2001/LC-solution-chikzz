#define ff first
#define ss second
class Solution {
    map<pair<int,int>,int>dist;
public:
    int minimumCost(vector<int>& s, vector<int>& t, vector<vector<int>>& sr) {
        //set all distances to inf
        dist[{t[0],t[1]}]=1e9;
        for(auto it:sr) {
            dist[{it[0],it[1]}]=dist[{it[2],it[3]}]=1e9;
        }
        
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{s[0],s[1]}});
        
        while(!pq.empty()) {
            auto [wt,P]=pq.top();pq.pop();
            wt*=-1;
            auto [i,j]=P;
            if(wt>dist[{i,j}])continue;
            if(i==t[0]&&j==t[1])return wt;
            if(dist[{t[0],t[1]}]>wt+abs(t[0]-i)+abs(t[1]-j)) {
                dist[{t[0],t[1]}]=wt+abs(t[0]-i)+abs(t[1]-j);
                pq.push({-dist[{t[0],t[1]}],{t[0],t[1]}});
            }
            
            for(auto it:sr) {
                if(dist[{it[0],it[1]}]>wt+abs(i-it[0])+abs(j-it[1])) {
                    dist[{it[0],it[1]}]=wt+abs(it[0]-i)+abs(it[1]-j);
                    pq.push({-dist[{it[0],it[1]}],{it[0],it[1]}});
                }
                if(dist[{it[2],it[3]}]>wt+abs(i-it[0])+abs(j-it[1])+min(abs(it[0]-it[2])+abs(it[1]-it[3]),it[4])) {
                    dist[{it[2],it[3]}]=wt+abs(i-it[0])+abs(j-it[1])+min(abs(it[0]-it[2])+abs(it[1]-it[3]),it[4]);
                    pq.push({-dist[{it[2],it[3]}],{it[2],it[3]}});
                }
            }
        }
        
        return dist[{t[0],t[1]}];
    }
};