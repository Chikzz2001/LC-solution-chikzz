class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n=board.size();
        reverse(board.begin(),board.end());
        for(int i=0;i<n;i++)
        {
            if(i&1)
                reverse(board[i].begin(),board[i].end());
        }
        
        queue<int>Q;
        set<int>vis;
        Q.push(1);
        vis.insert(1);
        
        int level=0;
        while(!Q.empty())
        {
            int size=Q.size();
            while(size--)
            {
                int curr=Q.front();Q.pop();
            
                if(curr==n*n)
                return level;
            
                for(int i=1;i<=6;i++)
                {
                    if(curr+i>n*n)break;
                    int xx=(curr+i-1)/n,yy=(curr+i-1)%n;
                    if(!vis.count(curr+i))
                    {
                        vis.insert(curr+i);
                        if(board[xx][yy]!=-1)
                        Q.push(board[xx][yy]);
                        else
                        Q.push(curr+i);
                    }
                }
            }
               level++;
        }
        return -1;
    }
};