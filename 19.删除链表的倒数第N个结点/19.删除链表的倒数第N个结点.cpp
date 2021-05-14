/*
 * @Descroption: LeetCode 19. 删除链表的倒数第 N 个结点
 * @Author: EmoryHuang
 * @Date: 2021-03-22 15:37:36
 * @解题思路:
 * 方法一应该很容易想到，设置快慢2个指针，快指针先走n步，然后快慢一起走，直到快指针走到最后
 * 方法二是评论里看到的，点子很秀，递归到最后一个结点，然后跳过倒数第 n 个结点
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
    // 方法一：双指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;
        ListNode *p = head, *q = head;
        for (int i = 0; i < n; i++) q = q->next;
        if (!q) return head->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }

    // 方法二：递归
    // int c = 0;
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if (!head) return nullptr;
    //     head->next = removeNthFromEnd(head->next, n);
    //     c++;
    //     if (n == c) return head->next;
    //     return head;
    // }
};