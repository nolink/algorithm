/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    
    if(NULL == head || NULL == head->next){
        return head;
    }
    
    struct ListNode* temp = head->next;
    /*seperate sorted list*/
    head->next=NULL;
    
    struct ListNode* before_cursor = head;
    struct ListNode* cursor = head;
    
    struct ListNode* swap = NULL;
    
    while(temp){
        /*if all sorted are less than current unsorted element, what to do?*/
        while(cursor && cursor->val <= temp->val){
            before_cursor=cursor;
            cursor=cursor->next;
        }
        
        swap = temp;
        temp = temp->next;
        /*there exists an element larger than the current unsorted element*/
        if(cursor && before_cursor == cursor){
            swap->next=cursor;
            head=swap;
        }else if(cursor){
            before_cursor->next=swap;
            swap->next=cursor;
        }else{
            before_cursor->next=swap;
            swap->next=NULL;
        }
        
        before_cursor=cursor=head;
    }
    
    return head;
}