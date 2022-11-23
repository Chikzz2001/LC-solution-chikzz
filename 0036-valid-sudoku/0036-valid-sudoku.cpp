class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //check each row
        for(auto &x:board)
        {
            int hash=0;
            for(auto &y:x)
            {
                if(y!='.')
                {
                    int bit=y-48;
                    if(hash&(1<<bit))return 0;
                    hash|=(1<<bit);
                }
            }
        }
        
        //check every column
        for(int i=0;i<9;i++)
        {
            int hash=0;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    int bit=board[j][i]-48;
                    if(hash&(1<<bit))return 0;
                    hash|=(1<<bit);
                }
            }
        }
        
        //check each small-grids
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                //(i,j)-->represents the top-left index of each smaller grid 
                int hash=0;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(board[k][l]!='.')
                        {
                            int bit=board[k][l]-48;
                            if(hash&(1<<bit))return 0;
                            hash|=(1<<bit);
                        }
                    }
                }
            }
        }
        return 1;
    }
};