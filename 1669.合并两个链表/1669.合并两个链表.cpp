/*
 * @Descroption: LeetCode 1669. 合并两个链表
 * @Author: EmoryHuang
 * @Date: 2021-07-24 13:39:52
 * @解题思路:
 * 链表基础题
 * 先找到链表1的第a-1个节点，找到链表1的第b+1个节点
 * 再找到链表2的尾节点，之后连接即可
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // 找到链表1的第a-1个节点
        ListNode* p = list1;
        for (int i = 0; i < a - 1; i++) p = p->next;
        // 找到链表1的第b+1个节点
        ListNode* q = p->next;
        for (int i = a; i < b + 1; i++) q = q->next;
        // 找到链表2的尾节点
        ListNode* tail = list2;
        while (tail->next) tail = tail->next;
        // 连接
        p->next = list2;
        tail->next = q;
        return list1;
    }
};