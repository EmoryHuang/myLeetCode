/*
 * @Descroption: 剑指 Offer 31. 栈的压入、弹出序列
 * @Author: EmoryHuang
 * @Date: 2023-07-25 10:10:31
 * @Method:
 * 使用栈进行模型
 * 若栈顶元素等于出栈元素则出栈
 */

import java.util.*;

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> st = new Stack<>();
        int cnt = 0;
        for (int num : pushed) {
            st.push(num);
            while (!st.isEmpty() && cnt < popped.length && st.peek() == popped[cnt]) {
                cnt++;
                st.pop();
            }
        }
        return cnt == popped.length;
    }
}