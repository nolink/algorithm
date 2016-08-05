/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp{
  bool operator()(ListNode* n1, ListNode* n2)  {
      return n1->val > n2->val;
  }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto head : lists){
            while(head){
                q.push(head);
                head = head->next;
            }
        }
        ListNode aux = ListNode(0), *head = &aux;
        while(!q.empty()){
            head->next = q.top();
            q.pop();
            head = head->next;
        }
        if(head) head->next = NULL;
        return aux.next;
    }
};
