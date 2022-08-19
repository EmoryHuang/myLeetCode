/*
 * @Descroption: LeetCode 1413. 逐步求和得到正数的最小值
 * @Author: EmoryHuang
 * @Date: 2022-08-09 08:55:08
 * @Method:
 * 找到数组中依次累积的最小和sum，满足要求的最小正数为 1 - sum
 */

class Solution {

  public int minStartValue(int[] nums) {
    int ans = 0, sum = 0;
    for (int num : nums) {
      sum += num;
      ans = Math.min(ans, sum);
    }
    return 1 - ans;
  }
}
