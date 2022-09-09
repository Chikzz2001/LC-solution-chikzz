class Solution {
    
    //The trick in solving the question is the implementation of the comparator function appropriately.
    
    //THE IDEA IS TO SORT THE GIVEN ARRAY INTO A FORMAT SUCH THAT 
    //ON BASIS OF A CERTAIN PARAMETER(either attack or defence) WE SORT THE ARRAY IN INCREASING ORDER
    //AND FOR SIMILAR ELEMENT(of that parameter on basis of which it is sorted) WE KEEP THE
    //OTHER PARAMETER SORTED IN DECREASING ORDER.
    
    //an stl analogy would be set<multiset<int,greater<int>>S;
    
    //THE USE OF THIS COMPARATOR FUNCTION IS WHEN WE
    //TRAVERSE THE SET OF SAME ELEMENTS(paramater used for sorting) WE DO NOT 
    //HAVE A MAX ELEMENT(of the other parameter) BEFOREHAND FOR INCREMENTING THE ANSWER
    
    
    //eg:[[1,1],[2,1],[2,2],[1,2]]
    //after sorting on comp function:[[1,2],[1,1],[2,2],[2,1]]
    
    //when we traverse from [2,1] to [2,2] (2 is the similar element and it is the parameter 
    //on basis of which sorting is done)we do not increment ans as max till now is 1.
    //then when we move to smaller set(1) we have max(m)=2 
    
    static bool comp(const vector<int>& v1,const vector<int>& v2)
    {
        if(v1[0]!=v2[0])
            return v1[0]<v2[0];
        return v1[1]>v2[1];
    }
public:

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        
        sort(properties.begin(),properties.end(),comp);
        
        int m=INT_MIN;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(properties[i][1]<m)ans++;
           if(properties[i][1]>=m)m=properties[i][1];
        }
   return ans;
        
    }
};