class Solution {
    vector<vector<int>>dp;
    int W,N;
    int helper(vector<vector<int>>& books,int i,int level) {
        if(i==N)return 0;
        
        if(dp[i][level]!=-1)return dp[i][level];
        int minn=1e9;
        int s=0,mh=0;
        for(int j=i;j<N&&s+books[j][0]<=W;j++) {
            s+=books[j][0];
            mh=max(mh,books[j][1]);
            minn=min(minn,mh+helper(books,j+1,level+1));
        }
        
        return dp[i][level]=minn;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        W=shelfWidth,N=books.size();
        // sort(books.begin(),books.end(),[&](const vector<int>& v1,const vector<int>& v2) {
        //     return v1[1]==v2[1]?v1[0]<v2[0]:v1[1]<v2[1];
        // });
        
        // int sum=0;
        // for(int i=0;i<N;i++)sum+=books[i][0];
        // int maxxl=sum/W+10;
       
        dp=vector<vector<int>>(N,vector<int>(1001,-1));
        return helper(books,0,0);
    }
};