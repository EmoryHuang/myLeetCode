/*
 * @Descroption: LeetCode 946. 验证栈序列
 * @Author: EmoryHuang
 * @Date: 2022-08-31 09:05:16
 * @Method:
 * 模拟，使用stack模拟入栈，
 * 若栈非空，并且栈顶元素等于出栈元素，则出栈
 */


class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<Integer>();
        int cnt = 0;
        for (int num : pushed) {
            stack.push(num);
            while (!stack.isEmpty() && cnt < popped.length && stack.peek() == popped[cnt]) {
                cnt++;
                stack.pop();
            }
        }
        return cnt == popped.length;
    }
}