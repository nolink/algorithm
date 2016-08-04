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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for(int i=0;fast && i < n;i++){
            fast = fast->next;
        }
        if(fast){
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            if(slow && slow->next){
                slow->next = slow->next->next;
            }
        }else if(head){
            head = head->next;
        }
        return head;
    }
};
