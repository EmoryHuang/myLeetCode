/*
 * @Descroption: LeetCode 761. 特殊的二进制序列
 * @Author: EmoryHuang
 * @Date: 2022-08-08 09:22:58
 * @Method:
 * 每个特殊的二进制序列必定以1开头，以0结尾
 * 通过维护计数器cnt统计1与0数量的差值
 * 若cnt == 0，则递归地生成子序列
 */

class Solution {

  public String makeLargestSpecial(String s) {
    if (s.length() <= 2) return s;
    int cnt = 0, left = 0;
    List<String> res = new ArrayList<String>();
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == '1') {
        cnt++;
      } else {
        cnt--;
        if (cnt == 0) {
          res.add("1" + makeLargestSpecial(s.substring(left + 1, i)) + "0");
          left = i + 1;
        }
      }
    }
    Collections.sort(res, (a, b) -> b.compareTo(a));
    StringBuilder sb = new StringBuilder();
    for (String str : res) sb.append(str);
    return sb.toString();
  }
}
