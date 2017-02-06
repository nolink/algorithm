/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(NULL == head) return head;
        unordered_map<RandomListNode*, RandomListNode*> m;
        RandomListNode* p = head;
        while(p){
            m[p] = new RandomListNode(p->label);
            p = p->next;
        }
        p = head;
        while(p){
            m[p]->next = p->next ? m[p->next] : NULL;
            m[p]->random = p->random ? m[p->random] : NULL;
            p = p->next;
        }
        return m[head];
    }
};
