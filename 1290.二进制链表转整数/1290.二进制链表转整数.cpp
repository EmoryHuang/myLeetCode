/*
 * @Descroption: LeetCode 1290. 二进制链表转整数
 * @Author: EmoryHuang
 * @Date: 2021-08-26 19:00:35
 * @Method:
 * 简单题，位运算
 * 每读到一个节点，则左移一位
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
    int getDecimalValue(ListNode* head) {
        if (head == nullptr) return 0;
        int ans = 0;
        while (head) {
            ans = (ans << 1) + head->val;
            head = head->next;
        }
        return ans;
    }
};