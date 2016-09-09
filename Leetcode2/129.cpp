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
    int sumNums(TreeNode* root, int sink){
        int ret = 0;
        if(root){
            int aux = sink + root->val;
            if(NULL == root->left && NULL == root->right) return aux;
            if(root->left) ret += sumNums(root->left, aux * 10);
            if(root->right) ret += sumNums(root->right, aux * 10);
        }
        return ret;
    }
    int sumNumbers(TreeNode* root) {
        return sumNums(root, 0);
    }
};
