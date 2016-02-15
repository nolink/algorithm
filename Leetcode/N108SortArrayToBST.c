/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    
    if(NULL == nums || numsSize <= 0){
        return NULL;
    }
    
    struct TreeNode* current = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    int mid = 0;
    if(numsSize >= 3){
        mid = numsSize / 2;
        current->val = nums[mid];
        current->left = sortedArrayToBST(nums, mid);
        current->right = sortedArrayToBST(&nums[mid+1], numsSize - mid - 1);
    }else if(numsSize == 2){
        current->val = nums[1];
        struct TreeNode* left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        left->val = nums[0];
        left->left = NULL;
        left->right = NULL;
        current->left = left;
        current->right = NULL;
    }else{
        current->val = nums[0];
        current->left = NULL;
        current->right = NULL;
    }
    return current;
    
}