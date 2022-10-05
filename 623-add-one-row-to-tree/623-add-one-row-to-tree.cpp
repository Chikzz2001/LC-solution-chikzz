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
    void dfs(TreeNode* root,int depth,int &val)
    {
        if(!root)return;
        
        if(depth==2)
        {
            //if depth is the last node feasible in the tree then we cannot consider the left and right to not be nullptr!!!
                TreeNode* l=root->left;
                TreeNode* nodel=new TreeNode(val,l,nullptr);
                root->left=nodel;
            
                TreeNode* r=root->right;
                TreeNode* noder=new TreeNode(val,nullptr,r);
                root->right=noder;

            return;
        }
      
        dfs(root->left,depth-1,val);
        dfs(root->right,depth-1,val);
        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(!root){TreeNode* node=new TreeNode(val);return node;}
        
       if(depth==1){TreeNode* node=new TreeNode(val,root,nullptr);return node;}
        dfs(root,depth,val);
        return root;
    }
};