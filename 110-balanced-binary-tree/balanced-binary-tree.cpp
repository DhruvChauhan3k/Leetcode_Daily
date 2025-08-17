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
    pair<bool,int> check(TreeNode* root)
    {
        if(root==NULL)
        {
            return {true,0};
        }
        pair<int,int>l=check(root->left);
        pair<int,int>r=check(root->right);
        if(l.first==true and r.first==true)
        {
            if(abs(l.second-r.second)<=1)
            {
                return {true,1+max(l.second,r.second)};
            }
            return {false,0}; 
        }
        return {false,0};
    }
    bool isBalanced(TreeNode* root) {
        pair<bool,int>p=check(root);
        return p.first;
    }
};