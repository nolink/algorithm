/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head, *hsecond = NULL, *p = NULL;
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
        }
        if(slow){
            hsecond = slow->next;
            //break the chain
            slow->next = NULL;
        }
        //reverse hsecond to end
        slow = hsecond;
        while(slow && slow->next){
            fast = slow->next;
            slow->next = fast->next;
            fast->next = hsecond;
            hsecond = fast;
        }
        //chain together
        ListNode aux(0);
        p = &aux;
        while(head && hsecond){
            p->next = head;
            head = head->next;
            p = p->next;
            p->next = hsecond;
            hsecond = hsecond->next;
            p = p->next;
            p->next = NULL;
        }
        if(hsecond) p->next = hsecond;
        if(head) p->next = head;
        head = aux.next;
    }
};
