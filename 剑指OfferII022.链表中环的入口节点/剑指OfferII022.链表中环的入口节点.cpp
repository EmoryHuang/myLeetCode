/*
 * @Descroption: 剑指 Offer II 022. 链表中环的入口节点
 * @Author: EmoryHuang
 * @Date: 2021-08-03 20:12:44
 * @Method:
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
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                fast = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};