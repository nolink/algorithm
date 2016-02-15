/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    
    struct ListNode* t1 = head;
    struct ListNode* t2 = head;
    
    while(NULL != t1 && NULL != t1->next){
        t2 = t1->next;
        t1->next = t2->next;
        t2->next = head;
        head = t2;
    }
    
    return head;
}