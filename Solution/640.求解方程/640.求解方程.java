/*
 * @Descroption: LeetCode 640. 求解方程
 * @Author: EmoryHuang
 * @Date: 2022-08-10 09:09:31
 * @Method:
 * 模拟
 * 遍历字符串，将其转换为 k * x = val
 */

class Solution {

  public String solveEquation(String equation) {
    int factor = 0, val = 0;
    int i = 0, n = equation.length(), sign = 1;
    while (i < n) {
      // 等号变号
      if (equation.charAt(i) == '=') {
        sign = -1;
        i++;
        continue;
      }
      // 加减号处理
      int s = sign;
      if (equation.charAt(i) == '+') {
        i++;
      } else if (equation.charAt(i) == '-') {
        s = -s;
        i++;
      }
      // 数字处理
      int num = 0;
      boolean flag = false;
      while (i < n && equation.charAt(i) >= '0' && equation.charAt(i) <= '9') {
        flag = true;
        num = num * 10 + equation.charAt(i) - '0';
        i++;
      }
      // 变量处理
      if (i < n && equation.charAt(i) == 'x') {
        factor += flag ? s * num : s;
        i++;
      } else {
        val += s * num;
      }
    }
    if (factor == 0) return val == 0 ? "Infinite solutions" : "No solution";
    if (val % factor != 0) return "No solution";
    return "x=" + (-val / factor);
  }
}
