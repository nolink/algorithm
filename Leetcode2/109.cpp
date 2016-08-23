/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* transfer(ListNode* head, ListNode* tail){
        if(head == tail) return NULL;
        ListNode *fast = head, *slow = head;
        while(fast != tail){
            fast = fast->next;
            if(fast != tail){
                fast = fast->next;
                slow = slow->next;
            }
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = transfer(head, slow);
        root->right = transfer(slow->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return transfer(head, NULL);
    }
};
