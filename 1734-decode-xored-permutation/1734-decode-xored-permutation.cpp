class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        
        vector<int>res(n+1);
        int odd_pos_XOR=0;
        for(int i=1;i<n;i+=2)odd_pos_XOR^=encoded[i];
        int XOR_N=0;
        for(int i=1;i<=n+1;i++)XOR_N^=i;

        res[0]=odd_pos_XOR^XOR_N;
       
        for(int i=1;i<=n;i++)
            res[i]=res[i-1]^encoded[i-1];
        
        return res;
    }
};

/*

en[0]=res[0]^en[1]^en[2]^en[3]^res[4]
en[1]=res[1]^res[2]
en[2]=res[2]^res[3]
en[3]=res[3]^res[4]

res[0]^res[4]=()

re

110
101
*/