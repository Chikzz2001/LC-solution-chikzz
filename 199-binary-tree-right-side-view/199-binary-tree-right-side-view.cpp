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
    vector<int>res;
    void rev_postorder(TreeNode* root,int level)
    {
        if(!root)return ;
        if(res.size()==level)
        {
            res.push_back(root->val);
        }
        rev_postorder(root->right,level+1);
        rev_postorder(root->left,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        rev_postorder(root,0);
        return res;
    }
};