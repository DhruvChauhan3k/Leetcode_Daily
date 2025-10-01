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
    pair<int,int> create(TreeNode*root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int>l=create(root->left);
        pair<int,int>r=create(root->right);
        int exc=max(l.first,l.second)+max(r.first,r.second);
        int inc=root->val+l.second+r.second;
        return {inc,exc};
    }
    int rob(TreeNode* root) {
        pair<int,int>ans= create(root);
        return max(ans.first,ans.second);
    }
};