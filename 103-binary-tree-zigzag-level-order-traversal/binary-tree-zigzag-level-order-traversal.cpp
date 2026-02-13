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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool lefToRight = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int> arr;
            while(size--){               
                    TreeNode* temp = q.front();
                    q.pop();
                    arr.push_back(temp->val);
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                                   
            }
            if(!lefToRight)
                reverse(arr.begin(),arr.end());
            ans.push_back(arr);
            lefToRight = !lefToRight;
            
        }
        return ans;
    }
};