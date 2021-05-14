/*
 * @Descroption: LeetCode 377. 组合总和 Ⅳ
 * @Author: EmoryHuang
 * @Date: 2021-04-24 13:38:36
 * @解题思路:
 * `dp[i]` 代表组合数为 `i` 时,使用 `nums` 中的数能组成的组合数的个数
 * 当`1 ≤ i ≤ target`时，如果存在一种排列，其中的元素之和等于`i`，
 * 则该排列的最后一个元素一定是数组 `nums` 中的一个元素。
 * 假设该排列的最后一个元素是 `num`，则一定有`num ≤ i`，对于元素之和等于 `i-num` 的每一种排列，
 * 在最后添加 `num` 之后即可得到个元素之和等于`i`的排列
 */

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int num : nums)
                // 在 target 之前的数字组合数可能超过 INT_MAX
                if (i >= num && dp[i - num] < INT_MAX) {
                    dp[i] += dp[i - num];
                }
        return dp[target];
    }
};