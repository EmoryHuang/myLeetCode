/*
 * @Descroption: LeetCode 1408. 数组中的字符串匹配
 * @Author: EmoryHuang
 * @Date: 2022-08-06 09:03:44
 * @Method:
 * 简单模拟题，暴力遍历
 */

class Solution {

  public List<String> stringMatching(String[] words) {
    List<String> res = new ArrayList<>();
    int n = words.length;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && words[j].contains(words[i])) {
          res.add(words[i]);
          break;
        }
      }
    }
    return res;
  }
}
