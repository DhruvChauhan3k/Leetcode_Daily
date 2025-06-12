/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         if (!root) return "";

        string ss;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr) {
                ss+=to_string(curr->val)+",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                ss+="null,";
            }
        }

        return ss;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
          if (data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // Left child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    curr->left = new TreeNode(stoi(item));
                    q.push(curr->left);
                }
            }

            // Right child
            if (getline(ss, item, ',')) {
                if (item != "null") {
                    curr->right = new TreeNode(stoi(item));
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));