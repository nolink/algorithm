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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head, *q = head;
        while(p && p->next){
            q = p->next;
            p->next = q->next;
            q->next = head;
            head = q;
        }
        return head;
    }
};
