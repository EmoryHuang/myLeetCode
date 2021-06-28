/*
 * @Descroption: ��ָ Offer 06. ��β��ͷ��ӡ����
 * @Author: EmoryHuang
 * @Date: 2021-06-28 17:09:00
 * @����˼·:
 * ���⣬reverse, �ݹ�, ջ
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

    // �ݹ�
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