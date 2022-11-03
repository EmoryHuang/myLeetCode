/*
 * @Descroption: LeetCode 1800. 最大升序子数组和
 * @Author: EmoryHuang
 * @Date: 2022-10-07 11:00:02
 * @Method:
 * 简单题，遍历数组寻找最大升序子数组和
 */

class Solution {
    public int maxAscendingSum(int[] nums) {
        int ans = nums[0], cur = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1])
                cur += nums[i];
            else
                cur = nums[i];
            ans = Math.max(ans, cur);
        }
        return ans;
    }
}