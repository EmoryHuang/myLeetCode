/*
 * @Descroption: 剑指 Offer II 090. 环形房屋偷盗
 * @Author: EmoryHuang
 * @Date: 2021-08-09 20:14:44
 * @Method:
 * 动态规划
 * 第一个和最后一个不能同时抢，不抢第一个的时候，最后一个可抢可不抢；另一种情况同理
 * dp[i] 表示到第i个房间为止能偷盗的最大金额
 * 状态转移方程：dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
 */

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n);
        int ans = 0;
        // 不偷第一个
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        ans = dp[n - 1];
        // 不偷最后一个
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return max(ans, dp[n - 2]);
    }
};