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
    map<int,int>m;
    bool check_pal()
    {
        bool odd=0;
        for(auto [x,y]:m)
        {
            if(y&1){if(odd)return 0;odd=1;}
        }
        return 1;
    }
    
    int helper(TreeNode* root)
    {
        if(!root)return 0;
        if(!root->left&&!root->right)
        {
            m[root->val]++;
            bool res=check_pal();
            m[root->val]--;
            return res?1:0;
        }
        
        m[root->val]++;
        int left=helper(root->left);
        int right=helper(root->right);
        m[root->val]--;
        return left+right;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return helper(root);
    }
};