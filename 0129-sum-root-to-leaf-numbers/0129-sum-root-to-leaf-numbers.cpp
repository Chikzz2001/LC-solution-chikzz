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
    int res=0;
    void helper(TreeNode* root,int val) {
        if(!root)return;
        val=val*10+root->val;
        if(!root->left&&!root->right){res+=val;return;}
        helper(root->left,val);
        helper(root->right,val);
    }
public:
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return res;
    }
};