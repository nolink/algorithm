/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if(NULL == headA || NULL == headB){
        return NULL;
    }
    
    struct ListNode* t1 = headA;
    struct ListNode* t2 = headB;
    
    int n1 = 0;
    int n2 = 0;
    int diff = 0;
    while(t1){
        n1++;
        t1 = t1->next;
    }
    
    while(t2){
        n2++;
        t2 = t2->next;
    }
    
    diff = n1 > n2 ? n1 - n2 : n2 - n1;
    if(n1 > n2){
        while(diff-- > 0){
            headA = headA->next;
        }
    }else{
        while(diff-- > 0){
            headB = headB->next;
        }
    }
    
    while(headA){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    return NULL;
}