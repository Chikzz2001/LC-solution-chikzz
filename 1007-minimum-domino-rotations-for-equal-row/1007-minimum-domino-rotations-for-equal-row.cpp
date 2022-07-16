class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
      vector<int>faceup(7,0),facedown(7,0),common(7,0);
        
        int n=tops.size();
        for(int i=0;i<n;i++)
        {
            if(tops[i]==bottoms[i])
            {
                common[tops[i]]++;
            }
            faceup[tops[i]]++;
            facedown[bottoms[i]]++;
        }
        
        int maxup=-1,maxdown=-1;
        for(int i=1;i<7;i++)
        {
            if(faceup[i]+facedown[i]-common[i]==n)
            {
                maxup=max(maxup,faceup[i]);
                maxdown=max(maxdown,facedown[i]);
            }
        }
        
        if(maxup==-1)return -1;
        return min(n-maxup,n-maxdown);
    }
};