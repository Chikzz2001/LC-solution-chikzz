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
#define min(a,b) a<b?a:b
class Solution {
    string res;
    void helper(TreeNode* root,string x) {
        if(!root) {
            return;
        }
        
        string y;
        y+='a'+root->val;
        x=y+x;
        
        if(!root->left&&!root->right) {
            if(res=="")res=x;
            else
            res=min(res,x);
        }
        
        helper(root->left,x);
        helper(root->right,x);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        helper(root,"");
        return res;
    }
};