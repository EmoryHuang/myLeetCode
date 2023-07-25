/*
 * @Descroption: LeetCode 739. 每日温度
 * @Author: EmoryHuang
 * @Date: 2023-07-22 10:38:15
 * @Method:
 * 维护递减单调栈
 */

import java.util.*;

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Deque<Integer> st = new LinkedList<>();
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && temperatures[st.peek()] < temperatures[i]) {
                int idx = st.poll();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
}