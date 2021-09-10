/*
 * @Descroption: LeetCode 1019. �����е���һ������ڵ�
 * @Author: EmoryHuang
 * @Date: 2021-07-23 19:10:58
 * @����˼·:
 * ά��һ���ݼ�ջ��ջ�д洢Ԫ���±�
 * �������飬��������ջ��Ԫ�ظ����������Ϊ�����ĵ�һ������ڵ�
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        vector<int> ans(nums.size());
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            // ά��һ���ݼ�ջ
            while (!st.empty() && nums[st.top()] < nums[i]) {
                ans[st.top()] = nums[i];  // �����ĵ�һ������ֵ
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};