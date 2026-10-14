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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        int i=1;
        while(i<preorder.size()&& preorder[i]<root->val){
            i++;
        }
        root->left=build(preorder,1,i-1);
        root->right=build(preorder,i,preorder.size()-1);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(preorder[start]);

        int i = start + 1;

        while (i <= end && preorder[i] < root->val) {
            i++;
        }

        root->left = build(preorder, start + 1, i - 1);
        root->right = build(preorder, i, end);

        return root;
    }
};