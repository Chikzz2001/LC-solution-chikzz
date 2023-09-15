class Solution {
    vector<int>g;
    int val=0;
    void generate(int i) {
        if(i==4) {
            g.push_back(val);
            return;
        }
        
        generate(i+1);
        val|=(1<<i);
        generate(i+1);
        val^=(1<<i);
    }
public:
    int flipLights(int n, int presses) {
        generate(0);
        
        int N=min(n,10);
        vector<vector<int>>v(4);
        for(int i=0;i<N;i++) {
            v[0].push_back(i);
        }
        for(int i=1;i<N;i+=2) {
            v[1].push_back(i);
        }
        for(int i=0;i<N;i+=2) {
            v[2].push_back(i);
        }
        for(int i=0;i<N;i+=3) {
            v[3].push_back(i);
        }
        
        unordered_set<int>S;
        for(int i=0;i<g.size();i++) {
            int val=0,c=0;
            for(int j=0;j<4;j++) {
                if(g[i]&(1<<j)) {
                    c++;
                }
            }
            int net=presses-c;
            if(net<0||net&1)continue;
            
            for(int j=0;j<4;j++) {
                if(g[i]&(1<<j)) {
                    for(int k=0;k<v[j].size();k++) {
                        val^=(1<<v[j][k]);
                    }
                }
            }
            S.insert(val);
        }
        
        return S.size();
    }
};