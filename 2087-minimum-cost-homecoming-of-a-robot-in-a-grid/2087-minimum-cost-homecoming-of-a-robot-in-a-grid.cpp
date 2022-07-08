class Solution {
public:
    int minCost(vector<int>& sP, vector<int>& hP, vector<int>& rC, vector<int>& cC) 
    {
        int cost=0;
        for(int i=min(sP[0],hP[0]);i<=max(sP[0],hP[0]);i++)
            cost+=rC[i];
        for(int i=min(sP[1],hP[1]);i<=max(sP[1],hP[1]);i++)
            cost+=cC[i];

        cost-=(rC[sP[0]]+cC[sP[1]]);
        return cost;
    }
};