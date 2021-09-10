/*
 * @Descroption: 剑指 Offer 25. 合并两个排序的链表
 * @Author: EmoryHuang
 * @Date: 2021-07-02 14:49:00
 * @解题思路:
 * 链表基础题，依次比较两个链表元素大小
 * 方法一：迭代
 * 方法二：递归
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
    // 方法一：迭代
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     ListNode *head = new ListNode(-1), *pre = head;
    //     while (l1 && l2) {
    //         if (l1->val < l2->val) {
    //             pre->next = l1;
    //             l1 = l1->next;
    //         } else {
    //             pre->next = l2;
    //             l2 = l2->next;
    //         }
    //         pre = pre->next;
    //     }
    //     pre->next = l1 ? l1 : l2;
    //     return head->next;
    // }

    // 方法二：递归
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        return nullptr;
    }
};