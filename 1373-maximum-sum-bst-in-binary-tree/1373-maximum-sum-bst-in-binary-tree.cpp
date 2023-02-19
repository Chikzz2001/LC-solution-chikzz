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
#define ff first
#define ss second
class Solution {
    int maxx=0;
    pair<int,pair<int,int>> helper(TreeNode* root) {
        if(!root)return {0,{INT_MIN,INT_MAX}};
        auto L=helper(root->left);
        auto R=helper(root->right);
        bool ok=1;
        if(root->val<=L.ss.ff)ok=0;
        if(root->val>=R.ss.ss)ok=0;
        if(ok) {
            maxx=max(maxx,root->val+L.ff+R.ff);
        }
        if(ok)
        return {L.ff+R.ff+root->val,{max({L.ss.ff,R.ss.ff,root->val}),min({L.ss.ss,R.ss.ss,root->val})}};
        return {0,{INT_MAX,INT_MIN}};
    }
public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxx;
    }
};