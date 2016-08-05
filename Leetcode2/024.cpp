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
    ListNode* swapPairs(ListNode* head) {
        ListNode *aux = NULL, *aux2 = NULL, *prev_aux = NULL;
        if(head && head->next){
            aux = head->next;
            head->next = aux->next;
            aux->next = head;
            head = aux;
            prev_aux = head->next;
            aux = prev_aux->next;
        }
        while(aux && aux->next){
            aux2 = aux->next;
            aux->next = aux2->next;
            aux2->next = aux;
            prev_aux->next = aux2;
            prev_aux = aux;
            aux = aux->next;
        }
        return head;
    }
};
