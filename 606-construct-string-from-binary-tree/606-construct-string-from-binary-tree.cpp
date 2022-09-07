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
 
public:
       void help(TreeNode* root,string &s)
    {
        if(!root)return;
        if(root->left)
        {
            s+="(";
            s+=to_string(root->left->val);
            help(root->left,s);
        s+=")";
        }
            if(root->right)
            {if(!root->left)s+="()";
                s+="(";
                s+=to_string(root->right->val);
                help(root->right,s);
                s+=")";
            }
            
    }
    string tree2str(TreeNode* root) {
        string ans="";
        if(!root)return ans;
        ans+=to_string(root->val);
        help(root,ans);
        return ans;
    }
};