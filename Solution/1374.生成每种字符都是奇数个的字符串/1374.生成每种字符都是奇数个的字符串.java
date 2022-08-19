/*
 * @Descroption: LeetCode 1374. 生成每种字符都是奇数个的字符串
 * @Author: EmoryHuang
 * @Date: 2022-08-01 09:05:05
 * @Method:
 * 简单题，直接取巧构造即可
 */


class Solution {

  public String generateTheString(int n) {
    StringBuffer sb = new StringBuffer();
    if (n % 2 == 1) {
      return sb.append("a".repeat(n)).toString();
    }
    return sb.append("a".repeat(n - 1)).append("b").toString();
  }
}
