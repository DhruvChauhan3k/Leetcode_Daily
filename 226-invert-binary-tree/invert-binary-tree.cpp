class Solution {
public:
    TreeNode* invertTree(TreeNode* &root) {
        // Base Case
        if(root==NULL)
            return NULL;
        // Swap the nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left); //Call the left substree
        invertTree(root->right); //Call the right substree
        return root; // Return the root
    }
};