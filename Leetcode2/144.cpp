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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        if(root) s.push(root);
        while(!s.empty()){
            auto aux = s.top();
            s.pop();
            ret.push_back(aux->val);
            if(aux->right) s.push(aux->right);
            if(aux->left) s.push(aux->left);
        }
        return ret;
    }
};
