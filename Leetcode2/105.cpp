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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if(preStart >= preorder.size() || inStart >= inEnd) return NULL;
        int rootVal = preorder[preStart], i = 0;
        for(;inStart + i<inEnd;i++){
            if(inorder[inStart + i] == rootVal) break;
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, inorder, preStart + 1, inStart, inStart + i);
        root->right = build(preorder, inorder, preStart + i + 1, inStart + i +1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size());
    }
};
