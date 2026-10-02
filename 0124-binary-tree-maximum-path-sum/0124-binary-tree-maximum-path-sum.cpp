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
private:
    int findMaxDownwardPath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftGain = max(
            0,
            findMaxDownwardPath(root->left)
        );

        int rightGain = max(
            0,
            findMaxDownwardPath(root->right)
        );

        return root->val + max(leftGain, rightGain);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr){
            return INT_MIN;
        }
        int leftContribution=max(0,findMaxDownwardPath(root->left));
        int rightContribution=max(0,findMaxDownwardPath(root->right));
        int currentPath=root->val+ leftContribution+rightContribution;
        int leftBest=maxPathSum(root->left);
        int rightBest=maxPathSum(root->right);
        return max({currentPath,leftBest,rightBest});
    }
};