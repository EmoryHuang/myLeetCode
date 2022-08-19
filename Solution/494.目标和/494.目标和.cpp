/*
 * @Descroption: LeetCode 494. 目标和
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:01:36
 * @解题思路:
 * `x` 为前面符号为`+`的集合；`y` 前面符号为`-`的集合
 * 所以题目可以转化为 `x - y = target`，又有 `sum(nums) = x + y`
 * 因此有 `x = (sum(nums) + target) / 2`
 * 将问题转化为求目标数组中和为 `x` 的组合方法个数，01 背包问题
 */

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;  // 计算所有元素之和
        if (target > sum || (target + sum) % 2 == 1) return 0;
        int posTarget = (target + sum) / 2;  // 新的目标值（需要的正数和）
        vector<int> dp(posTarget + 1);
        dp[0] = 1;
        for (int num : nums)
            for (int i = posTarget; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        return dp[posTarget];
    }
};