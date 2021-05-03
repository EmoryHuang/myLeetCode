/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy,*p=head,*q;
        while(p && p->val < x){
            p=p->next;
            pre=pre->next;
        }
        q=pre;
        while(p){
            if(p->val < x){
                pre->next = p ->next;
                p->next = q->next;
                q->next=p;
                q=p;
                p=pre->next;
            }else{
                p=p->next;
                pre=pre->next;
            }
        }
        return dummy->next;
    }
};