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
    void inorder(TreeNode* root, vector<int>& in){
        if(!root) return ;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);
        int s=0, e = in.size()-1;
        
        while(s<e){ 
            int sum = in[s]+in[e];
            if(sum == k) return true;
            if(sum>k) e--;
            else s++;
        }
        return false;
    }
};