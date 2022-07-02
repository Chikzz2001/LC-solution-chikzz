class Solution {
    void dfs(vector<vector<char>>& board,int i,int j,int &n,int &m)
    {
        board[i][j]='.';
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        for(int k=0;k<4;k++)
        {
            int nexti=i+dir[k][0];
            int nextj=j+dir[k][1];
            
            if(nexti>=0&&nextj>=0&&nexti<n&&nextj<m&&board[nexti][nextj]=='X')
                dfs(board,nexti,nextj,n,m);
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int ships=0;
        int n=board.size(),m=board[0].size();
        
          for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(board[i][j]=='X')
                 {
                     ships++;
                     dfs(board,i,j,n,m);
                 }
             }
          }
        return ships;
    }
};