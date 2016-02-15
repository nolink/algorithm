/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    if(NULL == p && NULL == q){
        return 1;
    }
    
    if((NULL == p && NULL != q) || (NULL != p && NULL == q)){
        return 0;
    }
    
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    
    return left && right && p->val == q->val;
    
}