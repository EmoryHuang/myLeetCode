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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p=head,*pre=dummy;
        while(p){
            if(p->val==val){
                ListNode *del = p;
                p = p->next;
                pre ->next = p;
                delete del;
            }else{
                pre=p;
                p=p->next;
            }
        }
        return dummy->next;
    }
};