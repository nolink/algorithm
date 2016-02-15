/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode* prev = head;
    struct ListNode* v = head;
    
    while(NULL != v){
        if(v->val == val && prev == v){
            prev = v->next;
            head = v->next;
            v = v->next;
        }else if(v->val == val){
            prev->next = v->next;
            v = v->next;
        }
        else{
            prev = v;
            v = v->next;
        }
    }
    
    return head;
    
}