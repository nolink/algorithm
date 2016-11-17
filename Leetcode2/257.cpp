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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(NULL == root) return {};
        if(NULL == root->left && NULL == root->right) return {to_string(root->val)};
        auto l = binaryTreePaths(root->left);
        auto r = binaryTreePaths(root->right);
        vector<string> ret;
        for(auto path : l) ret.push_back(to_string(root->val)+"->"+path);
        for(auto path : r) ret.push_back(to_string(root->val)+"->"+path);
        return ret;
    }
};
