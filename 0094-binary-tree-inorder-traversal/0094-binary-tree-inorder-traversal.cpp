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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==0){
            return ans;
        }
        vector<int>left=inorderTraversal(root->left);
        for(int x:left){
            ans.push_back(x);
        }
        
        ans.push_back(root->val);
        vector<int>right=inorderTraversal(root->right);
        for(int x:right){
            ans.push_back(x);
        }
        return ans;

    }
};