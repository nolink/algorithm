/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if(NULL != node && NULL != node->next){
        struct ListNode* next_node = node->next;
        node->val = next_node->val;
        node->next = next_node->next;
    }
}