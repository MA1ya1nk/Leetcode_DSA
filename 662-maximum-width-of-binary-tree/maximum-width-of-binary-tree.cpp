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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            int mini=q.front().second;
            int left,right;
            for(int i=0;i<sz;i++){
                auto fNode=q.front();
                q.pop();

                long long id=fNode.second-mini;
                TreeNode* node=fNode.first;

                if(i==0) left=id;
                if(i==sz-1) right=id;

                if(node->left) q.push({node->left,2*id+1});
                if(node->right) q.push({node->right,2*id+2});

            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};