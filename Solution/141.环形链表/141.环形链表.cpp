/*
 * @Descroption: LeetCode 141. 环形链表
 * @Author: EmoryHuang
 * @Date: 2021-03-25 09:14:36
 * @解题思路:
 * 定义两个指针，一快一满。慢指针每次只移动一步，而快指针每次移动两步。
 * 如果快指针反过来追上慢指针，就说明该链表为环形链表。否则快指针将到达链表尾部，该链表不为环形链表。
 */

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
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) return true;
        }
        return false;
    }
};