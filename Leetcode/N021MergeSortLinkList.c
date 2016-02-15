/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if(NULL == l1){
        return l2;
    }
    
    if(NULL == l2){
        return l1;
    }
    
    struct ListNode* merged = NULL;
    
    if(l1->val > l2->val){
        merged = l2;
        l2 = l2->next;
    }else{
        merged = l1;
        l1 = l1->next;
    }
    
    struct ListNode* head = merged;
    
    while(l1 && l2){
        if(l1->val > l2->val){
            merged->next=l2;
            l2=l2->next;
        }else{
            merged->next=l1;
            l1=l1->next;
        }
        merged = merged->next;
    }
    
    if(l1){
        merged->next=l1;
    }else{
        merged->next=l2;
    }
    
    return head;
}