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
        string s;
        serializehelper(root,s);
        return s;
    }
    void serializehelper(TreeNode* root,string& s){
        if(root==NULL){
            s+="#,";
            return ;
        }
        s+=to_string(root->val)+",";
        serializehelper(root->left,s);
        serializehelper(root->right,s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializehelper(ss);
    }
    TreeNode* deserializehelper(stringstream& ss){
        string value;
        getline(ss,value,',');
        if(value=="#"){
            return NULL;

        }
        TreeNode* root =new TreeNode(stoi(value));
        root->left=deserializehelper(ss);
        root->right=deserializehelper(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));