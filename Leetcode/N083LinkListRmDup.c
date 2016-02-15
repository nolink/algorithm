/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    
    if(NULL == head || NULL == head->next){
        return head;
    }
    
    struct ListNode* prev = head;
    struct ListNode* cur = head->next;
    
    while(NULL != cur){
        if(cur->val == prev->val){
            prev->next = cur->next;
            cur = cur->next;
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
    
    return head;
    
}