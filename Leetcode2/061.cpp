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
    ListNode* rotateRight(ListNode* head, int k) {
        if(NULL == head || NULL == head->next) return head;
        int n = 0;
        ListNode* aux = head;
        while(aux){
            n++;
            aux = aux->next;
        }
        k %= n;
        
        if(k <= 0) return head;
        
        aux = head;
        for(int i=0;i+k+1<n;i++) aux = aux->next;
        ListNode* newhead = aux->next;
        aux->next = NULL;
        
        aux = newhead;
        while(aux && aux->next) aux = aux->next;
        aux->next = head;
        return newhead;
    }
};
