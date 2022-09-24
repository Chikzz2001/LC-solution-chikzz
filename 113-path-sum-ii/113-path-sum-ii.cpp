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
    vector<vector<int>>res;
    void help(TreeNode* root,int &sum,vector<int>& temp,int &t)
    {
        if(!root)return;
        
        if(!root->left&&!root->right)
        {
            if(sum+root->val==t)
            {
            temp.push_back(root->val);
            res.push_back(temp);
            temp.pop_back();   
            }
            return;
        }
        
        temp.push_back(root->val);
        sum+=root->val;
        help(root->left,sum,temp,t);
        help(root->right,sum,temp,t);
        sum-=root->val;
        temp.pop_back();
    }
public:
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        if(!root)return {};
        int sum=0;
        vector<int>temp;
        help(root,sum,temp,targetSum);
        return res;
    }
};