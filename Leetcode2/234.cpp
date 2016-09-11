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
    bool isPalindrome(ListNode* head) {
        if(NULL == head || NULL == head->next) return true;
        ListNode *fast = head, *slow = head, *aux = NULL;
        int count = 1;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            count += (NULL == fast ? 1 : 2);
        }
        ListNode *nhead = count % 2 == 0 ? slow : slow->next;
        slow = nhead;
        while(slow && slow->next){
            aux = slow->next;
            slow->next = aux->next;
            aux->next = nhead;
            nhead = aux;
        }
        while(nhead){
            if(nhead->val != head->val) return false;
            nhead = nhead->next;
            head = head->next;
        }
        return true;
    }
};
