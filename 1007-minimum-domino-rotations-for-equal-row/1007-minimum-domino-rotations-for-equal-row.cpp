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
        
        vector<int>possibilities;
        for(int i=1;i<7;i++)
        {
            if(faceup[i]+facedown[i]-common[i]==n)
                possibilities.push_back(i);
        }
        
        if(!possibilities.size())
            return -1;
        
        int minn=1e9;
        for(auto &x:possibilities)
        {
            // int count1=0,count2=0;
            // for(int i=0;i<n;i++)
            // {
            //     if(tops[i]==x&&bottoms[i]==x)continue;
            //   if(tops[i]==x)  
            //   {
            //      count1++; 
            //   }
            //   else if(bottoms[i]==x)
            //   {
            //     count2++;
            //   }
            // } 
            // minn=min({minn,count1,count2});
            //cout<<faceup[x]<<" "<<faceup[x]<<"\n";
            minn=min({minn,n-faceup[x],n-facedown[x]});
        }
        
        return minn;
    }
};