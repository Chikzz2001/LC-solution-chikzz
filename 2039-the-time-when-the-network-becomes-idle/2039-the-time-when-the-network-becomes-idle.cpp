class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) 
    {
        int n=patience.size();
        vector<int>max_time(n,1e9);
        max_time[0]=0;
        
        queue<int>q;
        q.push(0);
        
        vector<vector<int>>network(n);
        for(auto &e:edges)
        {
            network[e[0]].push_back(e[1]);
            network[e[1]].push_back(e[0]);
        }
        while(!q.empty())
        {
            int node=q.front();q.pop();
            
            for(auto &nbr:network[node])
            {
                if(max_time[nbr]>max_time[node]+1)
                {
                    max_time[nbr]=max_time[node]+1;
                    q.push(nbr);
                }
            }
        }
        
        int max_active_time=0;
        for(int i=1;i<n;i++)
        {
            if(patience[i]>=2*max_time[i])
                max_active_time=max(max_active_time,2*max_time[i]);
            else
            {
                int packets=(2*max_time[i]-1)/patience[i]+1;
                //0 1 2 3
                //4
                //cout<<i<<" "<<packets<<" "<<max_time[i]<<"\n";
                int last_packet_dept=(packets-1)*patience[i];
                int position_of_last_packet=2*max_time[i]-last_packet_dept;
                int total_time=2*max_time[i]+(2*max_time[i]-position_of_last_packet);
                max_active_time=max(max_active_time,total_time);
            }
        }
        
        return max_active_time+1;
    }
};