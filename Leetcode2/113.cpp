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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(root){
            if(NULL == root->left && NULL == root->right){
                if(root->val == sum) ret.push_back({root->val});
            }else{
                auto sleft = pathSum(root->left, sum - root->val);
                auto sright = pathSum(root->right, sum - root->val);
                for(auto aux : {sleft, sright}){
                    for(auto s : aux){
                        vector<int> t(1, root->val);
                        t.insert(t.begin() + 1, s.begin(), s.end());
                        ret.push_back(t);
                    }
                }
            }
        }
        return ret;
    }
};
