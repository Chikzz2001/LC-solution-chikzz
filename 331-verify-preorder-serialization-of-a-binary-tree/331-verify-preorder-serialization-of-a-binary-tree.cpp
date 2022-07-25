class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int>tree;
    
        if(preorder.length()==1&&preorder[0]=='#')return true;
        vector<string>store;
        
        preorder+=",";
        string s;
        
        for(int i=0;i<preorder.length();i++)
        {
            if(preorder[i]==',')
            {
                store.push_back(s);
                s="";
            }
            else
            {
                s+=preorder[i];
            }
        }
        
        if(store[0]=="#")return false;
        tree.push(0);
        //0 1 2-->0-->no child visited
        //1-->left subtree is visited
        //2-->both subtrees is visited
        
        int idx=1;
        while(idx<store.size())
        {
            string value=store[idx++];
            if(tree.empty())return false;
            if(value!="#")
            {
                tree.push(0);
            }
            else
            {
                tree.top()++;
            }
            
            while(!tree.empty()&&tree.top()==2)
            {
                tree.pop();
                if(!tree.empty())
                tree.top()++;
            }
        }
        
        return tree.empty();
    }
};





