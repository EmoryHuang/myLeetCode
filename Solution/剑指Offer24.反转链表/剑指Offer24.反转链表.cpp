/*
 * @Descroption: 剑指 Offer 24. 反转链表
 * @Author: EmoryHuang
 * @Date: 2021-07-01 18:53:00
 * @解题思路:
 * 设置两个指针，pre指向空，cur指向head
 * next暂存cur.next，头插法反转
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};