/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if(NULL == root)
        return root;
    struct TreeNode *invertedRight = NULL;
    if(NULL != root->right){
        invertedRight = invertTree(root->right);
    }
    
    struct TreeNode *invertedLeft = NULL;
    if(NULL != root->left){
        invertedLeft = invertTree(root->left);
    }

    root->left = invertedRight;
    root->right = invertedLeft;
    
    return root;
}