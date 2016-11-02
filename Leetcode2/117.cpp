/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public: 
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head=root;//The left most node in the lower level
        TreeLinkNode *prev=NULL;//The previous node in the lower level
        TreeLinkNode *curr=NULL;//The current node in the upper level
        while (head){
            curr=head;
            prev=NULL;
            head=NULL;
            while (curr){
                if (curr->left){
                    if (prev)
                        prev->next=curr->left;
                    else 
                        head=curr->left;
                    prev=curr->left;
                }
                if (curr->right){
                    if (prev)
                        prev->next=curr->right;
                    else 
                        head=curr->right;
                    prev=curr->right;
                }
                curr=curr->next;
            }
        }
    }
};
