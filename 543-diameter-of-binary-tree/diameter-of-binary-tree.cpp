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
int ans=0;
class Solution {
public:
   
   int check(TreeNode*&root)
   {
       if(root==NULL)return 0;
       int a=check(root->left);
       int b=check(root->right);
        ans=max(ans,a+b);
        return max(a,b)+1;
   }
    int diameterOfBinaryTree(TreeNode* &root) {
        ans=0;
        check(root);
        return ans;
    }
};