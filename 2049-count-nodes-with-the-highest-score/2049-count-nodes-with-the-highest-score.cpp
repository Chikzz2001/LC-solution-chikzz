class Solution {
    void dfs(vector<int>& count,vector<vector<int>>& tree,int i)
    {
        count[i]=1;
        for(auto &x:tree[i])
        {
            dfs(count,tree,x);
            count[i]+=count[x];
        }
    }
public:
    int countHighestScoreNodes(vector<int>& p) {
        int n=p.size();
        vector<int>count(n);
        vector<vector<int>>tree(n);
        for(int i=0;i<n;i++)
        {
            if(p[i]==-1)continue;
            tree[p[i]].push_back(i);
        }
        dfs(count,tree,0);
        
        map<long long,int>m;

        for(int i=0;i<n;i++)
        {
            long long child1=1,child2=1;
            if(tree.size()>0)
            {
                if(tree[i].size()>=1)child1=count[tree[i][0]];
                child2=tree[i].size()>1?count[tree[i][1]]:1;
            }
            m[child1*child2*max(1LL,(long long)(n-count[i]))]++;
        }
        
        long long c=-1;
        for(auto [x,y]:m)
        {
            c=max(c,x);
        }
        return m[c];
    }
};