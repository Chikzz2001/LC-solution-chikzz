class Solution {
public:
    int wateringPlants(vector<int>& plants, int cap) 
    {
        int n=plants.size();
 
        //2 4 7 10
        int net=0,steps=0;
       for(int i=0;i<n;)
       {
           while(i<n&&net+plants[i]<=cap)
           {
               net+=plants[i++];
               steps++;
           }
           if(i==n)break;
           steps+=(2*i);
           net=0;
       }
        return steps;
    }
};

//1+1+4+1+6+1