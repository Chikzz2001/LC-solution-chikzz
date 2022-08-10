class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length();
        vector<vector<int>>graph(n);
        vector<int>indegree(n,0);
        
        for(auto &e:edges)
        {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        vector<vector<int>>dp(n,vector<int>(26,0));
    
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                dp[i][colors[i]-'a']++;
            }
        }
        
        int visited_nodes=0,res=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            visited_nodes++;
            
            for(auto &nbr:graph[node])
            {
                for(int i=0;i<26;i++)
                {
                    dp[nbr][i]=max(dp[nbr][i],dp[node][i]+(i==colors[nbr]-'a'));
                    res=max(res,dp[nbr][i]);
                }
                if(--indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
        
        return visited_nodes==n?res:-1;
    }
};