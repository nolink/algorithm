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
    TreeNode* helper(TreeNode* root){
        if(NULL == root || (NULL == root->left && NULL == root->right)) return root;
        if(NULL == root->left) return helper(root->right);
        if(NULL == root->right){
            root->right = root->left;
            root->left = NULL;
            return helper(root->right);
        }
        TreeNode* rightMost = helper(root->right);
        TreeNode* rightMostOfLeft = helper(root->left);
        rightMostOfLeft->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return rightMost;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};
