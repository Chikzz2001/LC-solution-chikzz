class Solution {
public:
    //do it later. Aj mann nhi hai :p
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>P;
        for (int i = 0; i < n; i++) {
            P.push_back({capital[i],profits[i]});
        }
        sort(P.begin(),P.end());
        priority_queue<int>pQ;
        int idx=0;
        for (int i=0;i<k;i++) {
            while (idx<n&&P[idx].first<=w) {
                pQ.push(P[idx++].second);
            }
            if (pQ.empty()) {
                break;
            }
            w+=pQ.top();pQ.pop();
        }
        return w;
    }
};