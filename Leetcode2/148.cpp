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
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode aux(0), *p = &aux;
        while(h1 && h2){
            if(h1->val <= h2->val){
                p->next = h1;
                h1 = h1->next;
            }else{
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        if(h1) p->next = h1;
        if(h2) p->next = h2;
        return aux.next;
    }
    ListNode* inner(ListNode* head, int n){
        if(n <= 1) return head;
        int expect = n / 2;
        ListNode *mid = head, *prev = head;
        for(int i=0;i<expect;i++){
            prev = mid;
            mid = mid->next;
        }
        prev->next = NULL;
        ListNode* h1 = inner(head, expect);
        ListNode* h2 = inner(mid, n - expect);
        return merge(h1, h2);
    }
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for(ListNode* p = head;p != NULL;p = p->next) n++;
        return inner(head, n);
    }
};
