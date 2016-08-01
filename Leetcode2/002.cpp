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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;
        int carry = 0, aux = 0;
        ListNode prevHead = ListNode(0), *head = &prevHead;
        while(l1 && l2){
            aux = carry + l1->val + l2->val;
            carry = aux / 10;
            head->next = new ListNode(aux % 10);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            aux = carry + l1->val;
            carry = aux / 10;
            head->next = new ListNode(aux % 10);
            head = head->next;
            l1 = l1->next;
        }
        while(l2){
            aux = carry + l2->val;
            carry = aux / 10;
            head->next = new ListNode(aux % 10);
            head = head->next;
            l2 = l2->next;
        }
        if(carry) head->next = new ListNode(carry);
        return prevHead.next;
    }
};
