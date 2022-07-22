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
    TreeNode* prev=NULL,*newroot=NULL;
    void flattenBST(TreeNode* root)
    {
        if(!root)return;
        
        flattenBST(root->left);
        
        if(prev)
        prev->right=root;
        root->left=NULL;
        
        if(!prev)newroot=root;
        prev=root;
        
        flattenBST(root->right); 
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        flattenBST(root);
        return newroot;
    }
};