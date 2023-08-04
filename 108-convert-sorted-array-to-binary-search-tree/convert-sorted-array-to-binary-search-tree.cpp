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
void check(TreeNode*&root,vector<int>&nums,int s,int e)
{
    if(s>e)return;
    int mid=(e+s)/2;
    root=new TreeNode(nums[mid]);
    check(root->left,nums,s,mid-1);
    check(root->right,nums,mid+1,e);
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode*root;
        check(root,nums,0,nums.size()-1);
        return root;
    }
};