/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* findLCA(TreeNode* root,int sv,int dv)
    {
        if(!root)return NULL;
        if(root->val==sv||root->val==dv)return root;
        
        TreeNode* l=findLCA(root->left,sv,dv);
        TreeNode* r=findLCA(root->right,sv,dv);
        
        if(!l)return r;
        if(!r)return l;
        
        return root;
    }
    
    bool to_dest(TreeNode* root,int dv,string &res)
    {
        if(!root)return 0;
        if(root->val==dv)
        {
            return 1;
        }
        
        if(to_dest(root->left,dv,res))
        {res+='L';return 1;}
         if(to_dest(root->right,dv,res))
         {res+='R';return 1;}
        return 0;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode* lca=findLCA(root,startValue,destValue);
        
        string res1,res2;
        to_dest(lca,startValue,res1);
        to_dest(lca,destValue,res2);
        
        for(auto &x:res1)x='U';
        reverse(res2.begin(),res2.end());
        return res1+res2;
    }
};