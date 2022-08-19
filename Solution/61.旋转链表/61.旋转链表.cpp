/*
 * @Descroption: LeetCode 61. 旋转链表
 * @Author: EmoryHuang
 * @Date: 2021-03-27 10:17:36
 * @解题思路: 找到原链表的最后一个节点，将其与原链表的头结点相连（成环），并统计链表长度，
 * 更新有效 k 值，从原链表的头节点出发，找到需要断开的点，进行断开
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        int len = 1;
        ListNode *p = head, *node;
        while (p->next) {
            len++;
            p = p->next;
        }
        k %= len;
        if (k == 0) return head;
        p->next = head;  //首尾相连
        for (int i = 0; i < len - k; i++) p = p->next;
        node = p->next;     //新的头节点
        p->next = nullptr;  //形成单链表
        return node;
    }
};