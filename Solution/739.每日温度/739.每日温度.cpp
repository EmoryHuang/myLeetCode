/*
 * @Descroption: LeetCode 739. 每日温度
 * @Author: EmoryHuang
 * @Date: 2021-07-19 16:05:38
 * @解题思路:
 * DFS 回溯
 * 维护一个递减栈，存储元素位置
 * 若当前元素大于栈顶元素，则找到了更高的温度，更新出栈元素对应的等待天数
 */

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};