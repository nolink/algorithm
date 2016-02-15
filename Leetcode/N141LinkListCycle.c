/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    if(NULL == head){
        return false;
    }
    
    if(head->next == head){
        return true;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    do{
        fast = fast->next;
        if(fast){
            if(fast == head || fast->next == head || fast == slow || fast->next == slow){
                return true;
            }
            slow = slow->next;
            fast = fast->next;
        }
    }while(fast);
	
    return false;
}
