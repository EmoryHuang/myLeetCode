/*
 * @Descroption: LeetCode 962. 最大宽度坡
 * @Author: EmoryHuang
 * @Date: 2021-07-10 14:58:57
 * @解题思路:
 * 首先正向遍历数组，栈中存放递减元素
 * 从后往前遍历, 这样每次遇到元素大于栈顶的就可以计算宽度，然后将栈顶弹出
 */

class Solution {
   public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++)
            // st 中存放递减元素
            if (st.empty() || nums[st.top()] > nums[i]) st.push(i);
        int ans = 0;
        // 从后往前遍历
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                ans = max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};