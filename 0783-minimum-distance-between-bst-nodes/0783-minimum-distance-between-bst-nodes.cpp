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
    void help(TreeNode* root,int &val,int &minn)
    {
        if(!root)return;
        
        help(root->left,val,minn);
        
        if(val>=0)
            minn=min(minn,root->val-val);
        
        val=root->val;
        
        help(root->right,val,minn);
    }
public:
    int minDiffInBST(TreeNode* root) {
    int minn=INT_MAX,val=-1;
        help(root,val,minn);
        return minn;
    }
};