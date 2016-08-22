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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        deque<TreeNode*> q;
        if(root) q.push_front(root);
        bool leftToRight = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> inner;
            for(int i=0;i<n;i++){
                if(leftToRight){
                    auto aux = q.front();
                    q.pop_front();
                    inner.push_back(aux->val);
                    if(aux->left) q.push_back(aux->left);
                    if(aux->right) q.push_back(aux->right);
                }else{
                    auto aux = q.back();
                    q.pop_back();
                    inner.push_back(aux->val);
                    if(aux->right) q.push_front(aux->right);
                    if(aux->left) q.push_front(aux->left);
                }
            }
            leftToRight = !leftToRight;
            ret.push_back(inner);
        }
        return ret;
    }
};
