class Solution {
    bool valid(vector<vector<char>>& board, int rM, int cM, char col,int di,int dj)
    {
        rM+=di,cM+=dj;
        if(rM<8&&cM<8&&rM>=0&&cM>=0)
        {
            if(board[rM][cM]==col||board[rM][cM]=='.')return 0;
        }
        else
        return 0;
        
        while(rM<8&&cM<8&&rM>=0&&cM>=0)
        {
            if(board[rM][cM]==col)
            {
                return 1;
            }
            else if(board[rM][cM]=='.')return 0;
            rM+=di,cM+=dj;
        }
        return 0;
    }
public:
    bool checkMove(vector<vector<char>>& board, int rM, int cM, char col) 
    {
        int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        
        for(int i=0;i<8;i++)
        {
            if(valid(board,rM,cM,col,dir[i][0],dir[i][1]))
            {
                return 1;
            }
        }
        return 0;
    }
};