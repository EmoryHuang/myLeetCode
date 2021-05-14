/*
 * @Descroption: LeetCode 86. 分隔链表
 * @Author: EmoryHuang
 * @Date: 2021-04-24 20:48:36
 * @解题思路: 遍历链表，寻找第一个大于等于 x 的元素并记录位置，
 * 之后再将小于 x 的结点移动到记录位置之后
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *p = head, *q;
        while (p && p->val < x) {  // 寻找第一个大于等于x的元素
            p = p->next;
            pre = pre->next;
        }
        q = pre;  // 记录位置
        while (p) {
            if (p->val < x) {  // 将小于x的结点移动到记录位置之后
                pre->next = p->next;
                p->next = q->next;
                q->next = p;
                q = p;
                p = pre->next;
            } else {
                p = p->next;
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};