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
    bool symmetric(TreeNode* left, TreeNode* right){
        if(NULL == left && NULL == right) return true;
        if(NULL == left || NULL == right) return false;
        return left->val == right->val && symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(NULL == root) return true;
        return symmetric(root->left, root->right);
    }
};
