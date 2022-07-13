#define ll long long int
class Solution {
    bool valid(vector<int>& dist,double hour,int speed)
    {
        double time=0;
        for(int i=0;i<dist.size()-1;i++)
        {
            double t=(1.0*dist[i])/(1.0*speed);
            time+=ceil(t);
            if(time>hour)return 0;
        }
        time+=(1.0*dist.back())/(1.0*speed);
        return time<=hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        ll lo=1,hi=1e7,res=-1;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            if(valid(dist,hour,mid))
            {
                res=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return res;
    }
};