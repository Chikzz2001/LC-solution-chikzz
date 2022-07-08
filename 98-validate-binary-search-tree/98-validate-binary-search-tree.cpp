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
#define ll long long
class Solution 
{
    bool valid(TreeNode* root,ll lower_bound,ll upper_bound)
    {
        if(!root)return 1;
        
        bool curr=root->val>lower_bound&root->val<upper_bound;
        return curr&valid(root->left,lower_bound,root->val)&valid(root->right,root->val,upper_bound);
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        return valid(root,-1e12,1e12);
    }
};