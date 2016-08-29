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
        int v = head->val;
        while(current){
            bool dup = false;
            while(current && current->val == v){
                dup = true;
                current = current->next;
            }
            if(dup){
                if(head->val == v){
                    head = prev = current;
                }else{
                    prev->next = current;
                }
            }else if(prev && prev->next != current){
                prev = prev->next;
            }
            if(current){
                v = current->val;
                current = current->next;
            }
        }
        return head;
    }
};
