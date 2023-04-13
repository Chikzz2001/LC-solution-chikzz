class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        int n=pushed.size(),m=popped.size();
        int i=0,j=0;
       while(i<n&&j<m)
       {
           s.push(pushed[i]);
           
           while(j<m&&!s.empty()&&popped[j]==s.top())
           {
               s.pop();
              j++; 
          }
           i++;
       }
        
        return (s.empty())?1:0;
    }
};