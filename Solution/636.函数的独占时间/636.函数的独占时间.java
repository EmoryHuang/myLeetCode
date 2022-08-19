/*
 * @Descroption: LeetCode 636. 函数的独占时间
 * @Author: EmoryHuang
 * @Date: 2022-08-07 13:09:18
 * @Method:
 * 栈
 * 当函数调用开始时，若栈非空，则停止当前函数，计算执行时间，然后将调用函数入栈。
 * 当函数调用结束时，将栈顶元素弹出，并计算相应的执行时间，若栈非空，继续执行栈中函数。
 */

class Solution {

  public int[] exclusiveTime(int n, List<String> logs) {
    int[] ans = new int[n];
    Deque<Integer> st = new ArrayDeque<>();
    int cur = -1;
    for (String log : logs) {
      String[] arr = log.split(":");
      int id = Integer.parseInt(arr[0]);
      int time = Integer.parseInt(arr[2]);
      if (arr[1].equals("start")) {
        if (!st.isEmpty()) ans[st.peekLast()] += time - cur;
        st.addLast(id);
        cur = time;
      } else {
        int func = st.pollLast();
        ans[func] += time - cur + 1;
        cur = time + 1;
      }
    }
    return ans;
  }
}
