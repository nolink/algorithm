/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    
    if(NULL == root || root->left == NULL || root->right == NULL){
        return;
    }
    root->left->next = root->right;
    if(NULL != root->next){
        root->right->next = root->next->left;
    }
    
    connect(root->left);
    connect(root->right);
    
    
    
}