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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root){
            if(root->left){
                ret = inorderTraversal(root->left);
            }
            ret.push_back(root->val);
            if(root->right){
                vector<int> r = inorderTraversal(root->right);
                ret.insert(ret.end(), r.begin(), r.end());
            }
        }
        return ret;
    }
};
