class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<int>max_time(n+1,0);
        vector<vector<int>>graph(n+1);
        vector<int>indegree(n+1,0);
        
        for(auto &r:relations)
        {
            graph[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        
        queue<int>q;
        int max_time_res=0;
        
        for(int i=1;i<=n;i++)
        {
            max_time[i]=time[i-1];
            if(!indegree[i])
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            
            max_time_res=max(max_time_res,max_time[curr]);
            for(auto &nbr:graph[curr])
            {
                max_time[nbr]=max(max_time[nbr],time[nbr-1]+max_time[curr]);
                if(--indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        
        return max_time_res;
    }
};