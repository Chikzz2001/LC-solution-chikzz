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
    int helper(TreeNode* root,int maxval)
    {
        if(!root)return 0;
        return (root->val>=maxval?1:0)+helper(root->left,max(maxval,root->val))+helper(root->right,max(maxval,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root,-1e4-1);
    }
};