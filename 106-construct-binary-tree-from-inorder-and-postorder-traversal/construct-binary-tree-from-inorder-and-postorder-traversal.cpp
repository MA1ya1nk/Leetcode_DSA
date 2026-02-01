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
    TreeNode* helper(vector<int>& in, vector<int>& post, int& ind, int s, int e){
        if(s>e || ind<0) return NULL;
        
        int piv=-1;
        for(int i=s;i<=e;i++){
            if(in[i] == post[ind]){
                piv=i;
                break;
            }
        }

        TreeNode* temp = new TreeNode(post[ind]);
        ind--;
        temp->right = helper(in, post, ind, piv+1, e);
        temp->left = helper(in, post, ind, s, piv-1);
        return temp;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int i = n-1;
        return helper(inorder, postorder, i, 0, n-1);
    }
};