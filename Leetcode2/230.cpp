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
public:
    int countNode(TreeNode* root){
        if(NULL == root) return 0;
        return countNode(root->left) + 1 + countNode(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int leftSize = 0;
        if(NULL != root->left) leftSize = countNode(root->left);
        if(k <= leftSize) return kthSmallest(root->left, k);
        if(k == leftSize + 1) return root->val;
        return kthSmallest(root->right, k - leftSize - 1);
    }
};
