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
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head || NULL == head->next) return head;
        ListNode *prev = head, *current = head->next;
        while(current){
            if(current->val == prev->val){
                prev->next = current->next;
            }else{
                prev = prev->next;
            }
            current = current->next;
        }
        return head;
    }
};
