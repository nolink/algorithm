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
    inline TreeNode* clone(TreeNode* origin){
        if(NULL == origin) return NULL;
        TreeNode* ret = new TreeNode(origin->val);
        ret->left = clone(origin->left);
        ret->right = clone(origin->right);
        return ret;
    }
    inline vector<TreeNode*> aux(int n, vector<vector<TreeNode*>>& dp){
        vector<TreeNode*>& ret = dp[n];
        if(n == 0 || !ret.empty()){
            return ret;
        }else if(n == 1){
            ret.push_back(new TreeNode(n));
        }else{
            vector<TreeNode*> children = aux(n-1, dp);
            for(auto child : children){
                //as parent
                auto current = new TreeNode(n);
                current->left = clone(child);
                ret.push_back(current);
                //as right child
                int level = 0;
                auto p = clone(child);
                while(p){
                    auto root = clone(child);
                    auto parent = root;
                    for(int i=0;i<level;i++){
                        parent = parent->right;
                    }
                    auto current2 = new TreeNode(n);
                    if(parent->right) current2->left = parent->right;
                    parent->right = current2;
                    ret.push_back(root);
                    level++;
                    p = p->right;
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n+1, vector<TreeNode*>());
        return aux(n, dp);
    }
};
