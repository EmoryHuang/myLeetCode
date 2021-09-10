/*
 * @Descroption: 剑指 Offer 06. 从尾到头打印链表
 * @Author: EmoryHuang
 * @Date: 2021-06-28 17:09:00
 * @解题思路:
 * 简单题，reverse, 递归, 栈
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
    // reverse
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        while (head != nullptr) {
            ans.push_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // 递归
    // void myprint(vector<int>& ans, ListNode* head) {
    //     if (head != nullptr) {
    //         myprint(ans, head->next);
    //         ans.push_back(head->val);
    //     }
    // }
    // vector<int> reversePrint(ListNode* head) {
    //     if (head == nullptr) return {};
    //     vector<int> ans;
    //     myprint(ans, head);
    //     return ans;
    // }
};