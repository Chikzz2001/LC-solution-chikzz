class Solution {
    vector<int>vis,res;
    bool cycle_found=0;
    //dfs
    void dfs(vector<vector<int>>& graph,int node)
    {
        vis[node]=1;
        for(auto &nbr:graph[node])
        {
            if(!vis[nbr])
                dfs(graph,nbr);
            else if(vis[nbr]==1)
            {
                cycle_found=1;
                return;
            }
        }
        vis[node]=2;
        res.push_back(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>graph(numCourses);
        
        vector<int>indegree(numCourses,0);
        for(auto &p:prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        
        vis=vector<int>(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
                dfs(graph,i);
        }
        
        reverse(res.begin(),res.end());
//         queue<int>Q;
//         for(int i=0;i<numCourses;i++)
//         {
//             if(indegree[i]==0)
//             {Q.push(i);res.push_back(i);}
//         }
        
//         while(!Q.empty())
//         {
//             int curr=Q.front();
//             Q.pop();
            
//             for(auto &nbr:graph[curr])
//             {
//                 if(--indegree[nbr]==0)
//                 {
//                     res.push_back(nbr);
//                     Q.push(nbr);
//                 }
//             }
//         }
        
        
        if(!cycle_found)
            return res;
        return {};
    }
};