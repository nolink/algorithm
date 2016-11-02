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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(NULL == head || m == n) return head;
        ListNode *p = head, *prev = NULL, *aux = NULL;
        for(int i=1;i<m;i++){
            prev = p;
            p = p->next;
        }
        while(p && p->next && m < n){
            aux = p->next;
            p->next = aux->next;
            if(NULL == prev){
                aux->next = head;
                head = aux;
            }else{
                aux->next = prev->next;
                prev->next = aux; 
            }
            m++;
        }
        return head;
    }
};
