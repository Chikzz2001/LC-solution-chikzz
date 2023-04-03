class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(),people.end());
        
        int boats=0;
        
        int n=people.size();

        int i=0,j=n-1;
        while(i<=j)
        {
            if(i==j)
            {
                boats++;
                break;
            }
            
            //this means the boat can take two people as sum of their weights is less than limit 
            if(people[i]+people[j]<=limit)
            {
                boats++;
                
                //as we have taken both the people in consideration we minimize the window from both sides
                i++;
                j--;
            }
            //in this case we send only people[j] via a single boat
            else
            {
                boats++;
                
                //we decrement j as we have sent people[j] by one boat
                j--;
            }
        }
        return boats;
    }
};

//1 2 2 3

//1 3-->send 3 via boat
//1 2-->send 1 and 2 via one boat
//2-->send 2 via a boat--->i==j case
