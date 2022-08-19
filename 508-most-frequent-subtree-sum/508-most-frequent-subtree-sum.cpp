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
    int max_freq=0;
    int dfs(TreeNode* root)
    {
        if(!root)return 0;
        int res=dfs(root->left)+dfs(root->right)+root->val;
        m[res]++;
        max_freq=max(max_freq,m[res]);
        return res;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int>res;
        for(auto &[x,y]:m)
        {
            if(y==max_freq)
            {
                res.push_back(x);
            }
        }
        return res;
    }
};