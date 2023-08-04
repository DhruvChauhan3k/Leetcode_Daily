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
 vector<int>ans;
class Solution {
public:
void check(TreeNode*root)
{
    if(root==NULL)return;
    check(root->left);
    ans.push_back(root->val);
    check(root->right);
}
    int kthSmallest(TreeNode* root, int k) {
        ans.clear();
        check(root);
        return ans[k-1];
    }
};