/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*> par;
        par[root]=NULL;
        queue<TreeNode*> qu;
        qu.push(root);
        int lvl=-1,p_lvl=-1,q_lvl=-1;
        while(!qu.empty()){
            int size=qu.size();
            lvl++;
            while(size--){
                auto top=qu.front();
                if(top==p) p_lvl=lvl;
                if(top==q) q_lvl=lvl;
                qu.pop();
                if(top->left){
                    par[top->left]=top;
                    qu.push(top->left);
                }    
                if(top->right){
                    qu.push(top->right);
                    par[top->right]=top;
                }    
            }
        }
        while(p_lvl>q_lvl){
            p=par[p];
            p_lvl--;
        }
        while(q_lvl>p_lvl){
            q=par[q];
            q_lvl--;
        }
        while(p!=q){
            p=par[p];
            q=par[q];
        }
        return p;
    }
};