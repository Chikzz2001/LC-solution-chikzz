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
    struct node
    {
        int minn,maxx,sum;
    };
    node helper(TreeNode* root)
    {
        if(!root)
            return {INT_MAX,INT_MIN,0};
        
        auto [lminn,lmaxx,lsum]=helper(root->left);
        auto [rminn,rmaxx,rsum]=helper(root->right);
        
        if(root->val>lmaxx&&root->val<rminn)
        {
            res=max(res,lsum+rsum+root->val);
            return {min({lminn,rminn,root->val}),max({lmaxx,rmaxx,root->val}),lsum+rsum+root->val};
        }
        
        res=max({res,lsum,rsum});
        return {INT_MIN,INT_MAX,0};
    }
public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return res;
    }
};