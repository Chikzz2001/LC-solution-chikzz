class Solution {
//     class DSU
//     {
//         public:
//         int *par,*size;
//         DSU(int n)
//         {
//             par=new int[n];
//             size=new int[n];
//             for(int i=0;i<n;i++)
//             {
//                 par[i]=i;
//                 size[i]=1;
//             }
//         }
        
//         int find(int x)
//         {
//             if(par[x]==x)return x;
//             return par[x]=find(par[x]);
//         }
        
//         bool join(int a,int b)
//         {
//             int pa=find(a);
//             int pb=find(b);
            
//             if(pa==pb)
//                 return 0;
            
//             if(size[pa]>=size[pb])
//             {
//                 par[pb]=pa;
//                 size[pa]+=size[pb];
//             }
//             else
//             {
//                 par[pa]=pb;
//                 size[pb]+=size[pa];
//             }
//             return 1;
//         }
//     };
    
public:
    int longestConsecutive(vector<int>& nums) 
    {
//         int n=nums.size();
//         unordered_map<int,int>m;
        
//         for(int i=0;i<n;i++)
//             m[nums[i]]=i;
        
//         DSU dsu(n);
        
//         for(auto &x:nums)
//         {
//             if(m.count(x-1))
//             {
//                 dsu.join(m[x],m[x-1]);
//             }
//             if(m.count(x+1))
//             {
//                 dsu.join(m[x],m[x+1]);
//             }
//         }
        
//          int maxx=0;
        
//         for(auto &x:nums)
//         {
//             dsu.find(m[x]);
//             maxx=max(maxx,dsu.size[m[x]]);
//         }
            
//         return maxx;
        
        if(nums.size()==0)return 0;
        unordered_set<int>present;
        for(auto &x:nums)
            present.insert(x);
        
        int longestStreak=1;
        for(auto &x:nums)
        {
            //we count the streak from the starting ele of the streak if the ele is present in the middle 
            //or the end of any streak then we ignore this processing
            if(!present.count(x-1))
            {
                int streak=1;
                int num=x;
                
                while(present.count(num+1))
                {
                    num++;
                    streak++;
                }
                
                longestStreak=max(longestStreak,streak);
            }
        }
        
        return longestStreak;
    }
};