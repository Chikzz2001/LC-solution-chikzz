class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        vector<vector<int>>dir;
        int n=mat.size(),m=mat[0].size();
        
        int init=0;int c=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                vector<int>v;
                if(j!=0)v.push_back(i*m+j-1);
                if(j!=m-1)v.push_back(i*m+j+1);
                if(i!=0)v.push_back((i-1)*m+j);
                if(i!=n-1)v.push_back((i+1)*m+j);
                dir.push_back(v);
                if(mat[i][j])init|=(1<<c);
                c++;
            }
        }
        
        queue<int>Q;
        Q.push(init);
        set<int>vis;
        vis.insert(init);
        int steps=0;
        
        while(!Q.empty()) {
            int sz=Q.size();
            while(sz--) {
                int curr=Q.front();Q.pop();
                if(curr==0)return steps;
                for(int i=0;i<dir.size();i++) {
                    int temp=curr;
                    temp^=(1<<i);
                    for(int x:dir[i]) {
                        temp^=(1<<x);
                    }
                    if(!vis.count(temp)) {
                        if(temp==0)return steps+1;
                        Q.push(temp);
                        vis.insert(temp);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

/*
0 1
2 3
*/