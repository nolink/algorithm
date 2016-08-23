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
    TreeNode* transfer(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        else if(start == end) return new TreeNode(nums[start]);
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = transfer(nums, start, mid - 1);
        root->right = transfer(nums, mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return transfer(nums, 0, nums.size() - 1);
    }
};
