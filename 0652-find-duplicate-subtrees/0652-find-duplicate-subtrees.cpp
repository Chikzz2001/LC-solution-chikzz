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
    unordered_map<string,int>rem;
    
    vector<TreeNode*> ans;
    string inorder(TreeNode* root)
    {
        if(!root){
            return "";
        }
        string left=inorder(root->left);
        
        string right=inorder(root->right);
        
        string curr = "l"+left+to_string(root->val)+right+"r";
        if(rem[curr] == 1){
            ans.push_back(root);
        }
        
        rem[curr]++;
        return curr;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        inorder(root);
        return ans;
    }
};