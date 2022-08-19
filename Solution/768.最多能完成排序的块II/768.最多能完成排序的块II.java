/*
 * @Descroption: LeetCode 768. 最多能完成排序的块 II
 * @Author: EmoryHuang
 * @Date: 2022-08-13 10:15:24
 * @Method:
 * 单调栈
 * 如果当前元素大于等于栈顶元素则入栈（新增块），即每块的最大值
 * 如果当前元素小于栈顶元素，则判断当前块是否可以被划分，直到栈顶元素小于等于当前元素为止
 */

class Solution {

  public int maxChunksToSorted(int[] arr) {
    Deque<Integer> stack = new ArrayDeque<>();
    for (int num : arr) {
      if (stack.isEmpty() || stack.peek() <= num) {
        // 当前元素大于等于栈顶元素则入栈（新增块）
        // 即每块的最大值
        stack.push(num);
      } else {
        // 当前元素小于栈顶元素，则判断当前块是否可以被划分
        // 直到栈顶元素小于等于当前元素为止
        int top = stack.pop();
        while (!stack.isEmpty() && stack.peek() > num) stack.pop();
        stack.push(top);
      }
    }
    return stack.size();
  }
}
