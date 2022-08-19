/*
 * @Descroption: LeetCode 1403. 非递增顺序的最小子序列
 * @Author: EmoryHuang
 * @Date: 2022-08-04 09:08:05
 * @Method:
 * 贪心思想，首先将 nums 进行排序
 * 然后从大到小选择元素，若该子序列中的元素之和大于剩余元素，则找到
 */


class Solution {

  public List<Integer> minSubsequence(int[] nums) {
    Arrays.sort(nums);
    int cur = 0, sum = Arrays.stream(nums).sum();
    List<Integer> res = new ArrayList<>();
    for (int i = nums.length - 1; i >= 0; i--) {
      cur += nums[i];
      res.add(nums[i]);
      if (cur > sum - cur) break;
    }
    return res;
  }
}
