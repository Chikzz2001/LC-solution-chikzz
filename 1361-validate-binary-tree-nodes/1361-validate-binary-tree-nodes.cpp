class Solution {
    bool validate_BT(vector<vector<int>>& graph,int root,vector<int>& vis)
    {
        if(vis[root])return 0;
        vis[root]=1;
        
        for(auto &nbr:graph[root])
        {
            if(!validate_BT(graph,nbr,vis))
                return 0;
        }
        return 1;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lC, vector<int>& rC) {
        vector<int>indegree(n,0);
        vector<vector<int>>graph(n);
        int i=0;
        for(auto &l:lC)
        {
            if(l!=-1)
            {
                indegree[l]++;
                graph[i].push_back(l);
            }
            i++;
        }
        
        i=0;
        for(auto &r:rC)
        {
             if(r!=-1)
            {
                indegree[r]++;
                graph[i].push_back(r);
            }
            i++;
        }
        
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {root=i;break;}
        }
        
        if(root==-1)return 0;
        
        vector<int>vis(n,0);
        bool valid=validate_BT(graph,root,vis);
        if(!valid)return 0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])return 0;
        }
        return 1;
    }
};