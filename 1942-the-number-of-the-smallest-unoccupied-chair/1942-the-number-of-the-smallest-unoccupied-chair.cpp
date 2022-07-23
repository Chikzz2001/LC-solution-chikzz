#define ff first
#define ss second
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        int n=times.size();
        vector<int>chairs(n,-1);
        priority_queue<int>get_chair;
        map<int,int>chair_map;
        for(int i=0;i<n;i++)
            get_chair.push(-i);
        
        vector<pair<int,int>>arrival,departure;
        
        for(int i=0;i<n;i++)
        {
            arrival.push_back({times[i][0],i});
            departure.push_back({times[i][1],i});
        }
        
        sort(arrival.begin(),arrival.end());
        sort(departure.begin(),departure.end());
        
        int i=0,j=0;
        
        while(i<n)
        {
            if(arrival[i].ff<departure[j].ff)
            {
                int assigned=-get_chair.top();
                get_chair.pop();
                if(arrival[i].ss==targetFriend)
                    return assigned;
                chair_map[arrival[i].ss]=assigned;
                i++;
            }
            else
            {
                int chair=chair_map[departure[j].ss];
                get_chair.push(-chair);
                j++;
            }
        }
        return chair_map[targetFriend];
    }
};