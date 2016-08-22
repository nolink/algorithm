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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> inner;
            for(int i=0;i<n;i++){
                auto aux = q.front();
                q.pop();
                inner.push_back(aux->val);
                if(aux->left) q.push(aux->left);
                if(aux->right) q.push(aux->right);
            }
            ret.push_back(inner);
        }
        return ret;
    }
};
