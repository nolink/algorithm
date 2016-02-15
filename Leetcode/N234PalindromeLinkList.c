/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int isPalindrome(struct ListNode* head) {
    if(NULL == head || NULL == head->next){
        return 1;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* preslow = NULL;
    do
    {
        fast = fast->next;
        if(fast)
        {
            fast = fast->next;
            preslow = slow;
            slow = slow->next;
        }
    }while(fast != NULL);
    preslow->next = NULL;
    
    struct ListNode* reverse = NULL;
    if(slow == NULL || slow->next == NULL){
        reverse = slow;
    }else{
        if(slow->next->next == NULL)
        {// two nodes
            struct ListNode* tail = slow->next;
            slow->next = NULL;
            tail->next = slow;
            reverse = tail;
        }
        else
        {
            struct ListNode* pre = slow;
            struct ListNode* cur = pre->next;
            pre->next = NULL;   // set tail
            struct ListNode* post = cur->next;
            while(post)
            {
                cur->next = pre;
                pre = cur;
                cur = post;
                post = post->next;
            }
            cur->next = pre;
            reverse = cur;
        }
    }
    
    while(NULL != head && NULL != reverse){
        if(head->val != reverse->val){
            return 0;
        }
        head=head->next;
        reverse=reverse->next;
    }
    
    return 1;
}