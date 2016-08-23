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
    int minDepth(TreeNode* root) {
        if(NULL == root) return 0;
        if(NULL == root->left && NULL == root->right) return 1;
        int lleft = minDepth(root->left);
        int lright = minDepth(root->right);
        return min(lleft == 0 ? INT_MAX : lleft, lright == 0 ? INT_MAX : lright) + 1;
    }
};
