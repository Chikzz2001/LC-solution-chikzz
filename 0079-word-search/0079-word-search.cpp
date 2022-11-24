class Solution {
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
   
    bool dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& vis,string& word,int idx)
    {
        if(idx==word.length()-1)
            return 1;
        
        vis[i][j]=1;
        
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            
            if(ni>=0&&nj>=0&&ni<board.size()&&nj<board[0].size()&&!vis[ni][nj]&&board[ni][nj]==word[idx+1])
            {if(dfs(board,ni,nj,vis,word,idx+1))return 1;}
        }
        
        vis[i][j]=0;
        return 0;
    }
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        char source=word[0];
        int len=word.length();
        
        int n=board.size(),m=board[0].size();
        
        if(len>n*m)return 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==source)
                {
                    vector<vector<bool>>vis(n,vector<bool>(m,0));
                    if(dfs(board,i,j,vis,word,0))
                        return 1;
                }      
            }
        }
        return 0;
    }
};