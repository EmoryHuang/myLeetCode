/*
 * @Descroption: LeetCode 1019. 链表中的下一个更大节点
 * @Author: EmoryHuang
 * @Date: 2021-07-23 19:10:58
 * @解题思路:
 * 维护一个递减栈，栈中存储元素下标
 * 遍历数组，若遇到比栈顶元素更大的数，即为遇见的第一个更大节点
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
            // 维护一个递减栈
            while (!st.empty() && nums[st.top()] < nums[i]) {
                ans[st.top()] = nums[i];  // 遇到的第一个更大值
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};