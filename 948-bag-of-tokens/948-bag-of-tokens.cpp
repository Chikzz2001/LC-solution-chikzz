class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //op1: -power +1(score)
        //op2: +power -1(score)
        
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        
        int score=0;

        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i];
                score++;
                i++;
            }
            else
            {
                if(i==j)return score;
                if(!score)return 0;
                power+=tokens[j];
                score--;
                j--;
            }
        }
        
        return score;
    }
};

/*

100 300 600 1000
900 700 400 0

*/