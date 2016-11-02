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
    bool isValid(TreeNode* root, int& maximum, int& minimum){
        if(NULL == root) return true;
        maximum = minimum = root->val;
        int leftMax = 0, leftMin = 0, rightMax = 0, rightMin = 0;
        if(root->left){
            bool leftValid = isValid(root->left, leftMax, leftMin);
            if(!leftValid || leftMax >= root->val) return false;
            minimum = leftMin;
        }
        if(root->right){
            bool rightValid = isValid(root->right, rightMax, rightMin);
            if(!rightValid || rightMin <= root->val) return false;
            maximum = rightMax;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        int maximum = 0, minimum = 0;
        return isValid(root, maximum, minimum);
    }
};
