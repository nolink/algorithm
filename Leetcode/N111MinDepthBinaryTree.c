/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    
    //parent is leaf
    if(NULL == root){
        return 0;
    }
    
    //leaf
    if(NULL == root->left && NULL == root->right){
        return 1;
    }
    
    if(NULL == root->left && NULL != root->right){
        return 1 + minDepth(root->right);
    }
    
    if(NULL == root->right && NULL != root->left){
        return 1 + minDepth(root->left);
    }
    
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    
    return left < right ? left + 1 : right + 1;
    
}