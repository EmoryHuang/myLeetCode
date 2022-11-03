/*
 * @Descroption: LeetCode 856. 括号的分数
 * @Author: EmoryHuang
 * @Date: 2022-10-09 09:29:33
 * @Method:
 * 栈
 * 依次遍历元素，若为（，则分数 0 入栈，否则
 * 若栈顶元素cur == 0, 则）前面只有（，分值为 1
 * 若栈顶元素cur != 0, 则cur为）前面的分值
 */

class Solution {
    public int scoreOfParentheses(String s) {
        Deque<Integer> st = new ArrayDeque<Integer>();
        st.addLast(0);
        for (char c : s.toCharArray()) {
            if (c == '(') {
                st.addLast(0);
            } else {
                int cur = st.pollLast();
                st.addLast(st.pollLast() + Math.max(cur * 2, 1));
            }
        }
        return st.peekLast();
    }
}