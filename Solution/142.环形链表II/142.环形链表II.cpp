/*
 * @Descroption: LeetCode 142. 环形链表 II
 * @Author: EmoryHuang
 * @Date: 2021-05-13 15:25:36
 * @解题思路:
 * 首先创建快慢指针，判断链表是否存在环
 * 然后找到入环结点，
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        // 判断是否有环
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