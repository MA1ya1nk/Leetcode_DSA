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
    TreeNode* build(vector<int>& pre, vector<int>& in, int s, int e,int& index){
          if(s>e) return NULL;
          int ind=-1;
          for(int i=s;i<=e;i++){
            if(pre[index]==in[i]){
                ind=i;
                break;
            }
          }

          TreeNode* temp = new TreeNode(pre[index++]);
          temp->left=build(pre,in,s,ind-1,index);
          temp->right=build(pre,in,ind+1,e,index);
          return temp;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int n=preorder.size(),temp=0;
        return build(preorder,inorder,0,n-1,temp);
    }
};