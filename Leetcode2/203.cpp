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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){
            head = head->next;
        }
        if(head){
            ListNode *prev = head, *p = head->next;
            while(p){
                if(p->val == val){
                    p = p->next;
                    prev->next = p;
                }else{
                    p = p->next;
                    prev = prev->next;
                }
            }
        }
        return head;
    }
};
