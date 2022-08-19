/*
 * @Descroption: LeetCode 1944. 队列中可以看到的人数
 * @Author: EmoryHuang
 * @Date: 2021-09-10 19:54:25
 * @Method:
 * 单调栈 + 逆序遍历
 * 最开始尝试了正序遍历，啪一下就超时了
 * 逆序遍历，维护一个递减栈，将第 i 个人与栈顶元素 j 比较，
 * 若 heights[i] > heights[j]，说明 i 能够看到 j，i 左侧的人看不到 j，则出栈，比较下一个栈顶元素
 * 否则 i 能够看到 j，i 看不到 j 右侧的人，退出比较
 */

class Solution {
   public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        // 逆序遍历
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty()) {
                ans[i]++;
                if (heights[i] > heights[st.top()])
                    // i 能够看到 j，i 左侧的人看不到 j，出栈，比较下一个栈顶元素
                    st.pop();
                else
                    // i 能够看到 j，i 看不到 j 右侧的人，退出比较
                    break;
            }
            st.push(i);
        }
        return ans;
    }
};