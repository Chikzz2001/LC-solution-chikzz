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
    vector<int>tour,mhl,mhr;
    map<int,int>h,first,last;
    void dfs(TreeNode* root,int height)
    {
        if(!root)return;
        h[root->val]=height;
        first[root->val]=tour.size();
        tour.push_back(root->val);
        dfs(root->left,height+1);
        dfs(root->right,height+1);
        last[root->val]=tour.size();
        tour.push_back(root->val);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root,0);
        //for(auto &t:tour)cout<<t<<" ";
        mhl=vector<int>(tour.size());
        mhr=vector<int>(tour.size());
        mhl[0]=mhr[tour.size()-1]=h[root->val];
     
        for(int i=1;i<tour.size();i++)mhl[i]=max(mhl[i-1],h[tour[i]]);
        for(int i=tour.size()-2;i>=0;i--)mhr[i]=max(mhr[i+1],h[tour[i]]);
        vector<int>res;
        for(int q:queries)
        {
            res.push_back(max(mhl[first[q]-1],mhr[last[q]+1]));
        }
        return res;
    }
};