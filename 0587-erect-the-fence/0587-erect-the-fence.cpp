class Solution {
    double area(int x1,int y1,int x2,int y2,int x3,int y3)
    {
        /*
            x1 y1 1
            x2 y2 1
            x3 y3 1
        x1(y2-y3)-y1(x2-x3)+(x2*y3-x3*y2);
        x1(y2-y3)+x2(y3-y1)+x3(y1-y2)
        */
        double ar=1.0*x1*(y2-y3)+1.0*x2*(y3-y1)+1.0*x3*(y1-y2);
        return ar;
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());
        
        set<pair<int,int>>res1;
        
        stack<pair<int,int>>st;
        
        //bottom-line chaining
        st.push({trees[0][0],trees[0][1]});
        for(int i=1;i<trees.size();i++)
        {
            while(st.size()>=2)
            {
                auto [x1,y1]=st.top();
                st.pop();
                auto [x2,y2]=st.top();
                st.push({x1,y1});
                if(area(x1,y1,x2,y2,trees[i][0],trees[i][1])>=0)break;
                st.pop();
            }
            st.push({trees[i][0],trees[i][1]});
        }
        while(!st.empty()){res1.insert(st.top());st.pop();}
        
        //top-line chaining
        st.push({trees[0][0],trees[0][1]});
        for(int i=1;i<trees.size();i++)
        {
            while(st.size()>=2)
            {
                auto [x1,y1]=st.top();
                st.pop();
                auto [x2,y2]=st.top();
                st.push({x1,y1});
                if(area(x1,y1,x2,y2,trees[i][0],trees[i][1])<=0)break;
                st.pop();
            }
            st.push({trees[i][0],trees[i][1]});
        }  
        while(!st.empty()){res1.insert(st.top());st.pop();}
        
        vector<vector<int>>res;
        for(auto &[x,y]:res1)res.push_back({x,y});
        
        return res;
        
    }
};