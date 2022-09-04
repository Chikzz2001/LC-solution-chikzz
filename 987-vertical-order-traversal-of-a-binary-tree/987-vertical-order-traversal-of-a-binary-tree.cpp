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
    map<int,map<int,vector<int>>>m;
    void dfs(TreeNode* root,int v_level,int h_level)
    {
        if(!root)return;
        
        m[v_level][h_level].push_back(root->val);
        dfs(root->left,v_level-1,h_level+1);
        dfs(root->right,v_level+1,h_level+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        dfs(root,0,0);
        
        vector<vector<int>>res;
        for(auto &[x,y]:m)
        {
            vector<int>temp;
            for(auto &[u,v]:y)
            {sort(v.begin(),v.end());
            for(auto &it:v)temp.push_back(it);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};