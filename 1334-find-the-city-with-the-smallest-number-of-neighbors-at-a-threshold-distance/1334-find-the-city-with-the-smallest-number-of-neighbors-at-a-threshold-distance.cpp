class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>>dist(n+1,vector<long long>(n+1,1e9));
        for(auto &e:edges)
        {
            dist[e[0]][e[1]]=dist[e[1]][e[0]]=e[2];
            dist[e[0]][e[0]]=dist[e[1]][e[1]]=0;
        }
        
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        
        int res=0,minn=1e9;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                if(dist[i][j]<=distanceThreshold)
                    c++;
            }
            if(c<=minn){res=i;minn=c;}
        }
        
        return res;
    }
};