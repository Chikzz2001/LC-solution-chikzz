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
    TreeNode* help(vector<int>& nums,int lo,int hi)
    {
        if(hi<lo)return NULL;
        
        int mid=lo+(hi-lo)/2;
        mid=((hi-lo)&1)?mid+1:mid;
        TreeNode* node=new TreeNode(nums[mid],help(nums,lo,mid-1),help(nums,mid+1,hi));
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return help(nums,0,n-1);
    }
};