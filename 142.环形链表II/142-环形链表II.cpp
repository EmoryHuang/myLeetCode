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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        // ÅÐ¶ÏÊÇ·ñÓÐ»·
        bool flag = false;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                flag = true;
                break;
            }
        }
        if (flag) {
            p = head;
            while (p != q) {
                p = p->next;
                q = q->next;
            }
            return p;
        }
        return nullptr;
    }
};