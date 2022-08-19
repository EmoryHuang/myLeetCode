/*
 * @Descroption: 剑指 Offer II 089. 房屋偷盗
 * @Author: EmoryHuang
 * @Date: 2021-08-09 19:51:14
 * @Method:
 * 动态规划
 * dp[i] 表示到第i个房间为止能偷盗的最大金额
 * 状态转移方程：dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
 */

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[n - 1];
    }
};