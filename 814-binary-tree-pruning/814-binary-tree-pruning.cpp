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
class Solution 
{
public:
    TreeNode* pruneTree(TreeNode* root) 
    {
        if(!root)return NULL;
        TreeNode* left=pruneTree(root->left);
        TreeNode* right=pruneTree(root->right);
        if(!left&&!right&&root->val!=1)return NULL;
        if(!left)root->left=NULL;
        if(!right)root->right=NULL;
        return root;
    }
};