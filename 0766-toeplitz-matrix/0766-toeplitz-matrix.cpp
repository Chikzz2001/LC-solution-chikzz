class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int b=matrix[0].size(),a=matrix.size();bool f1=1;
        for(int i=b-1;i>=0;i--)
        {int j=0,t=i;
         int s=matrix[j][t];bool f=1;
            while(j<a&&t<b)
            {
                if(matrix[j][t]!=s){f=0;break;}
                j++;t++;
            }
         if(!f){f1=0;break;}
        }
        if(!f1)return 0;
           
        for(int i=1;i<a;i++)
        {int j=0,t=i;
         int s=matrix[t][j];bool f=1;
            while(j<b&&t<a)
            {
                if(matrix[t][j]!=s){f=0;break;}
                j++;t++;
            }
         if(!f){f1=0;break;}
        }
        if(!f1)return 0;
        return 1;
    }
};