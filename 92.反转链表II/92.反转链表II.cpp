/*
 * @Descroption: LeetCode 92. 反转链表 II
 * @Author: EmoryHuang
 * @Date: 2021-03-18 15:31:36
 * @解题思路:
 * 首先将指针移动到 `left` 的前驱，然后使用头插法，直到 `right` 即可
 * 在需要反转的区间里，每遍历到一个节点，让这个新节点来到反转部分的起始位置
 */

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);  //设置一个头指针
        ListNode *p = head, *pre = dummy, *q;
        for (int i = 1; i < left; i++) {
            pre = pre->next;  //寻找 left 的前驱
        }
        p = pre->next;  //当前结点
        for (int i = left; i < right; i++) {
            q = p->next;  //当前结点的后继
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
        }
        return dummy->next;
    }
};