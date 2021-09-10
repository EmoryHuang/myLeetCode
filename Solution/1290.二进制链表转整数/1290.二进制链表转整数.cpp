/*
 * @Descroption: LeetCode 1290. ����������ת����
 * @Author: EmoryHuang
 * @Date: 2021-08-26 19:00:35
 * @Method:
 * ���⣬λ����
 * ÿ����һ���ڵ㣬������һλ
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