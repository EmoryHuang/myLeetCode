/*
 * @Descroption: 剑指 Offer II 038. 每日温度
 * @Author: EmoryHuang
 * @Date: 2021-08-04 19:47:35
 * @Method:
 * 维护一个单调栈
 * 遍历数组，若遇到比栈顶元素更大的元素，则更新出栈元素对应的等待天数
 * 并将更大的这个元素入栈
 */

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < temperatures.size(); i++) {
            // 维护递减栈
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                // 更新等待天数
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};