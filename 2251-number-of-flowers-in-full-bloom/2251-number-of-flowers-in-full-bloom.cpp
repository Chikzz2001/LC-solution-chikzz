class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<int>>P;
        for(int i=0;i<persons.size();i++) {
            P.push_back({persons[i],i});
        }
        sort(P.begin(),P.end());
        sort(flowers.begin(),flowers.end());
        
        int pp=0,fp=0;
        vector<int>res(P.size());
        while(pp<P.size()) {
            while(fp<flowers.size()&&flowers[fp][0]<=P[pp][0]) {
                pq.push({flowers[fp][1],flowers[fp][0]});
                fp++;
            }
            while(!pq.empty()) {
                if(pq.top().first<P[pp][0])pq.pop();
                else break;
            }
            res[P[pp][1]]=pq.size();
            pp++;
        }
        return res;
    }
};