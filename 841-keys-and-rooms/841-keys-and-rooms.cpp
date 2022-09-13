class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    queue<int>q;
    q.push(0);
    int n=rooms.size();
    vector<int>vis(n,0);
    vis[0]=1;

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
              int room=q.front();
                q.pop();

        for(int i=0;i<rooms[room].size();i++)
        {
            //cout<<room<<" "<<rooms[room][i]<<"\n";
            if(!vis[rooms[room][i]])
            {
                q.push(rooms[room][i]);
                vis[rooms[room][i]]=1;
            }
        }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])return 0;
    }
    return 1;
    }
};