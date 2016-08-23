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
    bool balanced(TreeNode* root, int& level){
        if(NULL == root) return true;
        int lleft = 0, lright = 0;
        if(balanced(root->left, lleft) && balanced(root->right, lright)){
            level = max(lleft, lright) + 1;
            return abs(lleft - lright) <= 1;
        }
        return false;
    }
    bool isBalanced(TreeNode* root) {
        int level = 0;
        return balanced(root, level);
    }
};
