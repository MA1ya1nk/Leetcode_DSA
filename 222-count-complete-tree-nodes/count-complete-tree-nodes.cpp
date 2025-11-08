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
void solve(TreeNode* root,int &i){
    if(!root) return ;
    solve(root->left,i);
    i++;
    solve(root->right,i);
    return ;
}
    int countNodes(TreeNode* root) {
        int i=0;
        solve(root,i);
        return i;
    }
};