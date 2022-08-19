/*
 * @Descroption: LeetCode 899. 有序队列
 * @Author: EmoryHuang
 * @Date: 2022-08-03 09:29:43
 * @Method:
 * 当 k = 1 时只能移动第一个字符，相当于寻找循环字符串的最小字典序
 * 当 k > 1 时由于没有规定移动次数，实际上相当于对字符串进行任意排列
 */


class Solution {

  public String orderlyQueue(String s, int k) {
    if (k == 1) {
      String ans = s;
      for (int i = 0; i < s.length(); i++) {
        String temp = s.substring(i) + s.substring(0, i);
        if (temp.compareTo(ans) < 0) {
          ans = temp;
        }
      }
      return ans;
    } else {
      char[] chars = s.toCharArray();
      Arrays.sort(chars);
      return new String(chars);
    }
  }
}
