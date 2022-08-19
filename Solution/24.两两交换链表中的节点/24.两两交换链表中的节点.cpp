/*
 * @Descroption: LeetCode 24. 两两交换链表中的节点
 * @Author: EmoryHuang
 * @Date: 2021-03-23 10:23:36
 * @解题思路: 链表问题，方法一比较常规，就是 p 和 pre 两个指针弯弯绕绕，然后 ac
 *  方法二使用了递归，比较巧妙
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
    // 方法一
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = head, *pre = dummy;
        while (p && p->next) {
            pre->next = p->next;
            p->next = p->next->next;
            pre->next->next = p;
            pre = p;
            p = pre->next;
        }
        return dummy->next;
    }

    // 方法二：递归
    // ListNode* swapPairs(ListNode* head) {
    //     if (!head || !head->next) return head;  //终止条件
    //     ListNode* next = head->next;
    //     head->next = swapPairs(next->next);  //返回已经交换完成后的子链表
    //     next->next = head;
    //     return next;
    // }
};
