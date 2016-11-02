/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeLinkNode* left, TreeLinkNode* right){
        if(NULL == left || NULL == right) return;
        left->next = right;
        dfs(left->left, left->right);
        dfs(left->right, right->left);
        dfs(right->left, right->right);
    }
    void connect(TreeLinkNode *root) {
        if(NULL == root) return;
        dfs(root->left, root->right);
    }
};
