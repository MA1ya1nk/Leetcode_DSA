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
    pair<int,bool> solve(TreeNode* root){
        if(!root) return {0,1};
        pair<int,bool> left=solve(root->left);
        pair<int,bool> right=solve(root->right);

        int leftHei=left.first;
        int rightHei=right.first;
        int hei=max(leftHei,rightHei)+1;
        pair<int,bool> ans;
        if(abs(leftHei-rightHei)>1 || !left.second || !right.second) return {hei,false};
        return {hei,true};
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans=solve(root);
        return ans.second;
    }
};