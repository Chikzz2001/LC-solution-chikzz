class Solution {
    bool valid(int i,int j,int &n,int &m)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    
    bool check(vector<vector<int>>& cells,int last_day,int &n,int &m)
    {
        vector<vector<bool>>marked_till_day(n,vector<bool>(m,0));
    
        for(int i=0;i<last_day;i++)
        marked_till_day[cells[i][0]-1][cells[i][1]-1]=1;
        
        queue<pair<int,int>>Q;
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        
        for(int i=0;i<m;i++)
        {
            if(!marked_till_day[0][i])
            {Q.push({0,i});marked_till_day[0][i]=1;}
        }
        
        while(!Q.empty())
        {
            auto [x,y]=Q.front();
            Q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
            
                if(valid(nx,ny,n,m)&&!marked_till_day[nx][ny])
                {
                    if(nx==n-1)return 1;
                    marked_till_day[nx][ny]=1;
                    Q.push({nx,ny});
                } 
            }
        }
        
        return 0;
    }
public:
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) 
    { 
        //if we can start after all given cells are flooded then there is no upper_bound to our 
        //last_day that we can wait infinite time and then start to walk as after all cells are flooded
        //the situation of the region remains same irrespective of how many days passes after that.
        
        //IN THE QUESTION IT SHOULD HAVE BEEN MENTIONED THE ANS(possibly 1e9) DURING THIS CASE.
        int lo=0,hi=cells.size(),res=-1;
        
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            
            if(check(cells,mid,n,m))
            {
                res=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        
        return res;
    }
};