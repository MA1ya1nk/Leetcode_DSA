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
    void preorder(TreeNode* root, string&  str){
        if(!root){
            str+="null,";
            return ;
        }
        str+=to_string(root->val)+",";
        preorder(root->left,str);
        preorder(root->right, str);
    }
    
    string serialize(TreeNode* root) {
        string str="";
        preorder(root,str);
        return str;
    }

    // Decodes your encoded data to tree.

    TreeNode* deserializeHelper(queue<string>& q) {
    string val = q.front();
    q.pop();

    if (val == "null") return nullptr;

    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeHelper(q);
    node->right = deserializeHelper(q);

    return node;
}

    TreeNode* deserialize(string data) {
        stringstream ss(data);
    string item;
    queue<string> q;

    // split by comma
    while (getline(ss, item, ',')) {
        q.push(item);
    }

    return deserializeHelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));