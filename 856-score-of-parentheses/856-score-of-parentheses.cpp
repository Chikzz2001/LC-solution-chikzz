class Solution {
    map<int,int>cl;

int f(string&str,int s,int e){
      if(abs(s-e)==1)return 1;
     if(s>=e)return 0;
    
      int end_point=cl[s];
        
      if(end_point==e)return 2*f(str,s+1,e-1);
      
      return f(str,s,end_point)+f(str,end_point+1,e);  
}

public:
    int scoreOfParentheses(string s) 
    {
        // int depth=-1;
        // int res=0;
        // for(int i=0;i<s.length();i++)
        // {
        //     if(s[i]=='(')
        //     depth++;
        //     else
        //     {
        //         if(s[i-1]=='(')
        //         res+=1<<depth;
        //         depth--;
        //     }
        // }
        // return res;
         int n=s.size();
     
     if(n==2)return 1;

     stack<int>st;

    for(int i=0;i<n;i++){
        if(s[i]=='('){
          st.push(i);
        }
        else{
            int open=st.top();
            st.pop();
            cl[open]=i;
         }
    }

    return f(s,0,n-1);

    }
};

/*

((())())
0 1 2 
1
*/