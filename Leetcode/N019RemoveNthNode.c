/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    if(NULL == head){
        return head;
    }
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = head;
    int total = 0;
    int slow_idx = 0;
    
    do{
        total++;
        fast = fast->next;
        if(fast){
            total++;
            slow_idx++;
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
    }while(fast);
    
    int to_delete = total - n;
    if(to_delete > total / 2){
        do{
            if(slow_idx == to_delete){
                prev->next = slow->next;
                break;
            }
            prev = slow;
            slow = slow->next;
            slow_idx++;
        }while(slow);
    }else if(to_delete == 0){
        head = head->next;
    }else{
        slow_idx = 1;
        prev = head;
        slow = prev->next;
        while(slow){
            if(slow_idx == to_delete){
                prev->next = slow->next;
                break;
            }
            prev = slow;
            slow = slow->next;
            slow_idx++;
        }
    }
    
    return head;
    
}