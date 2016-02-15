/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    
    if(NULL == root){
        *returnSize=0;
        return NULL;
    }
    
    int leftSize = 0;
    int rightSize = 0;
    
    char** left = binaryTreePaths(root->left, &leftSize);
    
    char** right = binaryTreePaths(root->right, &rightSize);
    
    char** current = NULL;
    int i=0;
    int j=0;
    
    if(NULL == left && NULL == right){
        *returnSize = 1;
        current = (char**)malloc(sizeof(char*));
        current[0] = (char*)malloc(11*sizeof(char));
        sprintf(current[0], "%d", root->val);
    }else if(NULL != left && NULL != right){
        *returnSize = leftSize + rightSize;
        current = (char**)malloc((*returnSize)*sizeof(char*));
        for(;i<leftSize;i++){
            current[i]=(char*)malloc(11*sizeof(char)+strlen(left[i]));
            sprintf(current[i], "%d->%s", root->val, left[i]);
            free(left[i]);
        }
        for(;j<rightSize;j++){
            current[i+j]=(char*)malloc(11*sizeof(char)+strlen(right[j]));
            sprintf(current[i+j], "%d->%s", root->val, right[j]);
            free(right[j]);
        }
    }else if(NULL != left && NULL == right){
        *returnSize = leftSize;
        current = (char**)malloc((*returnSize)*sizeof(char*));
        for(;i<leftSize;i++){
            current[i]=(char*)malloc(11*sizeof(char)+strlen(left[i]));
            sprintf(current[i], "%d->%s", root->val, left[i]);
            free(left[i]);
        }
    }else if(NULL != right && NULL == left){
        *returnSize = rightSize;
        current = (char**)malloc((*returnSize)*sizeof(char*));
        for(;i<rightSize;i++){
            current[i]=(char*)malloc(11*sizeof(char)+strlen(right[i]));
            sprintf(current[i], "%d->%s", root->val, right[i]);
            free(right[i]);
        }
    }
    
    
    return current;
}