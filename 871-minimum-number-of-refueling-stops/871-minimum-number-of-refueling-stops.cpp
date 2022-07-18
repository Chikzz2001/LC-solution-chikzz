class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int n=stations.size();
        if(!n)
            return target<=startFuel?0:-1;
        
        if(stations[0][0]>startFuel)
            return -1;
        
        if(target>stations[n-1][0])
            stations.push_back({target,0});
        n=stations.size();
        
        priority_queue<int>pQ;
        int stations_to_stop=0;
        
        int currFuel=startFuel-stations[0][0];
        pQ.push(stations[0][1]);
        
        for(int i=1;i<n;i++)
        {
            if(currFuel<stations[i][0]-stations[i-1][0])
            {
                if(!pQ.size())return -1;
                 while(pQ.size()&&currFuel<stations[i][0]-stations[i-1][0])
                {
                    currFuel+=pQ.top();
                    pQ.pop();
                    stations_to_stop++;
                }
                if(currFuel<stations[i][0]-stations[i-1][0])
                    return -1;
            }
             currFuel-=(stations[i][0]-stations[i-1][0]);
             pQ.push(stations[i][1]);
        }
        
        return stations_to_stop;
    }
};