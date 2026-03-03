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
    bool ans = false;
    void helper(TreeNode* root, int& sum, int target){
        if(!root) return ;
        if(!root->left && !root->right){
            sum += root->val;
            if(sum == target) ans = true;
            sum -= root->val;
            return ;
        }

        sum += root->val;
        helper(root->left,sum,target);
        helper(root->right,sum,target);
        sum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        // if(targetSum==0) return false;
        int sum = 0;
        helper(root,sum,targetSum);
        return ans;
    }
};