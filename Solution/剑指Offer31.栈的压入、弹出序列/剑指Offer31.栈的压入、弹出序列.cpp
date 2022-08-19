/*
 * @Descroption: 剑指 Offer 31. 栈的压入、弹出序列
 * @Author: EmoryHuang
 * @Date: 2021-07-03 14:25:53
 * @解题思路:
 * 模拟，使用stack模拟入栈，
 * 若栈非空，并且栈顶元素等于出栈元素，则出栈
 */

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int cnt = 0;
        for (int num : pushed) {
            st.push(num);
            // 若栈非空，并且栈顶元素等于出栈元素
            while (!st.empty() && cnt < popped.size() && st.top() == popped[cnt]) {
                cnt++;
                st.pop();
            }
        }
        return cnt == popped.size();
    }
};