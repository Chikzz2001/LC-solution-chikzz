int comb(int,int);
class Solution {
public:
    vector<vector<int>> generate(int n) {
// vector<vector<int>>a;
//         for(int j=0;j<=numRows-1;j++){
//         vector<int> ans;
//         for(int i=0;i<=j;i++)
//         {
//             ans.push_back(comb(j,i));
//         }
//         a.push_back(ans);
//     }
//         return a;
        
        vector<vector<int>>res;
        for(int i=0;i<n;i++)
        {
            vector<int>temp(i+1);
            temp[0]=1;
            temp.back()=1;
            for(int j=1;j<i;j++)
            {
                temp[j]=res.back()[j-1]+res.back()[j];
            }
            res.push_back(temp);
        }
        return res;
    }
};

// int comb(int a,int b)
// {
//  if(a==b||a==a-b)return 1;
//  else{
    
//      long ans=1;
//     for(int k=0;k<b;k++)
//     {
//        ans = ans*(a-k)/(k+1);    //calculating nCr 
//     }
//     return int(ans);
// }}

    
