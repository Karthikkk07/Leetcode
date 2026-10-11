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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);

        if (root == NULL) {
            return newNode;
        }

        TreeNode* curr = root;
        TreeNode* parent = NULL;

        while (curr != NULL) {
            parent = curr;

            if (val > curr->val) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        if (val > parent->val) {
            parent->right = newNode;
        }
        else {
            parent->left = newNode;
        }

        return root;
    }
};
