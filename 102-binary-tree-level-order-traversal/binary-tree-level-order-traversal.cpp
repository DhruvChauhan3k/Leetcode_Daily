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
int height(TreeNode*root)
{
    if(root==NULL)return 0;
    return max(height(root->right),height(root->left))+1;
}
void create(TreeNode*root,vector<vector<int>>&ans,int lvl)
{
    if(root==NULL)return;
    ans[lvl].push_back(root->val);
    create(root->left,ans,lvl+1);
    create(root->right,ans,lvl+1);
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h=height(root);
        vector<vector<int>>ans(h);
        create(root,ans,0);
        return ans;
    }
};