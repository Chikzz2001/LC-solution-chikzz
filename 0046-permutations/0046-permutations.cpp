class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) 
    {
	  if(num.size()==1)
          return {num};
        
        vector<vector<int>>res;
        permuteRecursive(num,0,res);
       
      return res;
    }
    
    //T(n)=n*T(n-1)=n*(n-1)*T(n-2)=n*n-1*n-2*....*T(1)= n!
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int>> &res)	
    {
		if(begin>=num.size()-1)
        {
            res.push_back(num);
            return;
        }
        
        for(int i=begin;i<num.size();i++)
        {
            swap(num[begin],num[i]);
            permuteRecursive(num,begin+1,res);
            swap(num[begin],num[i]);
        }
	}
};

//1 [2,3],[3,2]--->2 [3]  3 [2]
//2 [1,3],[3,1]--->1 [2]  3 [1]
//3 [2,1],[1,2]--->2 [1]  1 [2]


//123,132,213,231,321,312