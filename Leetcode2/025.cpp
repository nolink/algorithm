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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;
        bool headOK = false;
        for(auto tail = head, p = head, nhead = head, last = head, aux = head;NULL != tail;last = p, p = p->next){
            for(int i=1;i<k && tail;i++) tail = tail->next;
            if(NULL == tail) break;
            tail = tail->next;
            for(nhead = p;p->next != tail;nhead = aux){
                aux = p->next;
                p->next = aux->next;
                aux->next = nhead;
            }
            if(!headOK){
                head = nhead;
                headOK = true;
            }else{
                last->next = nhead;
            }
        }
        return head;
    }
};
