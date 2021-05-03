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
    ListNode* middleNode(ListNode* head) {
        ListNode *q=head,*p=head;
        while(q && q->next){
            p=p->next;
            q=q->next->next;
        }
        return p;
    }
};