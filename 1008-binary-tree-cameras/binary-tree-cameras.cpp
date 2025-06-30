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
    int check(TreeNode*root,int &sum)
    {
        if(root==NULL)return 1;
        int l=check(root->left,sum);
        int r=check(root->right,sum);
        if(l==0 or r==0){sum++;return 2;}
        else if(l==2 or r==2)return 1;
        else return 0;
    }
    int minCameraCover(TreeNode* root) {
        int sum=0;
        if(check(root,sum)==0)sum++;
        return sum;
    }
};