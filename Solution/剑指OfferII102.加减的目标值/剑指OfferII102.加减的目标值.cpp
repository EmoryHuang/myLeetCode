/*
 * @Descroption: 剑指 Offer II 102. 加减的目标值
 * @Author: EmoryHuang
 * @Date: 2021-11-11 19:35:58
 * @Method:
 * 动态规划
 * x 为前面符号为 + 的集合；y 前面符号为 - 的集合
 * 所以题目可以转化为 x - y = target，又有 sum(nums) = x + y
 * 因此有 x = (sum(nums) + target) / 2
 * 将问题转化为求目标数组中和为 x 的组合方法个数，01 背包问题
 * dp[i][j] 表示前 i 个数，和为 j 的方案数
 * 状态转移方程
 * dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
 */


class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target || (sum + target) % 2) return 0;
        // 需要的正数之和
        int pos = (sum + target) / 2;
        vector<int> dp(pos + 1);
        dp[0] = 1;
        for (int num : nums)
            // 倒序遍历
            for (int i = pos; i >= num; i--) dp[i] += dp[i - num];
        return dp[pos];
    }
};