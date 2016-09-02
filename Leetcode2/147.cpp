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
    ListNode* insertionSortList(ListNode* head) {
        if(NULL == head || NULL == head->next) return head;
        ListNode pre(0);
        ListNode *p = &pre, *unsorted = head, *aux = NULL;
        while(unsorted){
            aux = unsorted->next;
            while(p->next && p->next->val <= unsorted->val){
                p = p->next;
            }
            unsorted->next = p->next;
            p->next = unsorted;
            p = &pre;
            unsorted = aux;
        }
        return pre.next;
    }
};
