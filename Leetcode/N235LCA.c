/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(NULL == root){
        return NULL;
    }
    if(NULL == p){
        return q;
    }
    if(NULL == q){
        return p;
    }
    
    if(root->val == p->val || root->val == q->val){
        return root;
    }
    
    if(NULL == root->left || (p->val > root ->val && q->val > root->val )){
        return lowestCommonAncestor(root->right, p, q);
    }
    if(NULL == root->right || (p->val < root->val && q->val < root->val )){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
    
}