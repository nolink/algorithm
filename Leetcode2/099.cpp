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
private:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void traversal(TreeNode* root){
        if(NULL == root) return;
        traversal(root->left);
        if(NULL == first && prev->val >= root->val){
            first = prev;
        }
        if(NULL != first && prev->val >= root->val){
            second = root;
        }
        prev = root;
        traversal(root->right);
    }
    void recoverTree(TreeNode* root) {
        traversal(root);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
};
