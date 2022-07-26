class Solution {
    bool isvalid(vector<vector<char>>& board,int i,int j,char put)
    {
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==put)return 0;
            if(board[k][j]==put)return 0;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==put)return 0;
        }
        return 1;
    }
    bool backtrack(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k=1;k<=9;k++)
                    {
                       if(isvalid(board,i,j,'0'+k))
                       {
                           board[i][j]='0'+k;
                           if(backtrack(board))
                               return 1;
                       }
                    }
                    board[i][j]='.';
                    return 0;
                }
            }
        }
        return 1;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};