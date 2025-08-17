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
    bool check(TreeNode*root, long long  maxi, long long  mini)
    {
        if(root==NULL)return true;
        if(root->val<maxi and root->val>mini)
        {
            return check(root->left,root->val,mini) and check(root->right,maxi,root->val);
        }
        return false;
    } 
    bool isValidBST(TreeNode* root) {
        long long  mini=-1e10,maxi=1e10;
        return check(root->left,root->val,mini) and check(root->right,maxi,root->val);
    }
};