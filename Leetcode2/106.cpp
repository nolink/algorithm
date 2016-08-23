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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        if(inStart >= inEnd || postStart >= postEnd) return NULL;
        int rootVal = postorder[postEnd-1], i = 0;
        while(inStart + i < inEnd){
            if(inorder[inStart + i] == rootVal) break;
            i++;
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(inorder, postorder, inStart, inStart + i, postStart, postStart + i);
        root->right = build(inorder, postorder, inStart + i + 1, inEnd, postStart + i, postEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
