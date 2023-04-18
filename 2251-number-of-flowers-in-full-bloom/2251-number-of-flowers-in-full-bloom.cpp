class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        priority_queue<int>pQ;
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
                pQ.push(-flowers[fp][1]);
                fp++;
            }
            while(!pQ.empty()) {
                if(-pQ.top()<P[pp][0])pQ.pop();
                else break;
            }
            res[P[pp][1]]=pQ.size();
            pp++;
        }
        return res;
    }
};