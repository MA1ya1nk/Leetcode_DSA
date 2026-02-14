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
class BSTIterator {
public:
    vector<int> arr;
    int size=0,ind=0;
    void inorder(TreeNode* root, vector<int> &arr, int& size){
        if(!root) return ;

        inorder(root->left,arr, size);
        arr.push_back(root->val);
        size++;
        inorder(root->right,arr, size);
    }
    BSTIterator(TreeNode* root) {
        arr.push_back(-1);
        inorder(root,arr,size);
        
    }
    
    int next() {
        ind++;
        return arr[ind];
    }
    
    bool hasNext() {
        if(ind<size) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */