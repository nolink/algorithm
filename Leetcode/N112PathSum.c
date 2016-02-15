/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    
    if(NULL == root){
        return 0;
    }
    
    if(root->val == sum && NULL == root->left && NULL == root->right){
        return 1;
    }
    
    int leftValue = sum - root->val;
    bool leftHasPathSum = hasPathSum(root->left, leftValue);
    
    if(leftHasPathSum){
        return 1;
    }
    
    bool rightHasPathSum = hasPathSum(root->right, leftValue);
    
    return rightHasPathSum; 
}