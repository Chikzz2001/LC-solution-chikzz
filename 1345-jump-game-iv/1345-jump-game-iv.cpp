class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        int level=0;
        q.push(0);
        vector<bool>vis(n,0);
        vis[0]=1;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                int curr=q.front();
                q.pop();
                //cout<<curr<<" ";
                if(curr==n-1)return level;
                
                if((curr-1)>=0&&!vis[curr-1])
                {
                    if((curr-1)==n-1)return level+1;
                    q.push(curr-1);
                    vis[curr-1]=1;
                }
                if((curr+1)<n&&!vis[curr+1])
                {
                    if((curr+1)==n-1)return level+1;
                    q.push(curr+1);
                    vis[curr+1]=1;
                }
                vector<int>&v=mp[arr[curr]];
                for(int i=v.size()-1;i>=0;i--)
                {
                    if(!vis[v[i]])
                    {
                        if(v[i]==n-1)return level+1;
                        q.push(v[i]);
                        vis[v[i]]=1;
                    }
                }
                v.clear();
            }
            //cout<<"\n";
            level++;
        }
        return level;
    }
};