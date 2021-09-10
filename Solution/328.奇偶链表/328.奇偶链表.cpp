/*
 * @Descroption: LeetCode 328. 奇偶链表
 * @Author: EmoryHuang
 * @Date: 2021-05-28 16:19:17
 * @解题思路:
 * 分离奇偶链表，然后合并
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *even = head->next, *odd = head;
        ListNode* evenHead = even;  // 偶数链表的头节点
        while (even && even->next) {
            odd->next = odd->next->next;    // 链接下一个奇数节点
            even->next = even->next->next;  // 链接下一个偶数节点
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};